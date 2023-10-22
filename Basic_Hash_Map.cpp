#include <iostream>
#include <string>
#include <limits>
using namespace std;

struct KeyValue {
    string key;
    int value;
    KeyValue* next;

    KeyValue(const string& k, int v) : key(k), value(v), next(nullptr) {}
};

class HashMap {
private:
    const int TABLE_SIZE = 1000;
    KeyValue* table[1000];

public:
    HashMap() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = nullptr;
        }
    }

    unsigned int hash(const string& key) {
        unsigned int hash = 0;
        for (char c : key) {
            hash = (hash * 31) + c;
        }
        return hash % TABLE_SIZE;
    }

    KeyValue* createKeyValue(const string& key, int value) {
        return new KeyValue(key, value);
    }

    void insert(const string& key, int value) {
        int index = hash(key);
        KeyValue* newKeyValue = createKeyValue(key, value);
        newKeyValue->next = table[index];
        table[index] = newKeyValue;
    }

    int lookup(const string& key) {
        int index = hash(key);
        KeyValue* current = table[index];
        while (current) {
            if (current->key == key) {
                return current->value;
            }
            current = current->next;
        }
        return -1; // Key not found
    }

    void deleteKey(const string& key) {
        int index = hash(key);
        KeyValue* current = table[index];
        KeyValue* prev = nullptr;

        while (current) {
            if (current->key == key) {
                if (prev == nullptr) {
                    table[index] = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    void displayHashMap() {
        cout << "Hash Map Contents:" << endl;
        for (int i = 0; i < TABLE_SIZE; i++) {
            KeyValue* current = table[i];
            if (current) {
                while (current) {
                    cout << "  Key: " << current->key << ", Value: " << current->value << endl;
                    current = current->next;
                }
            }
        }
    }

    void cleanupHashMap() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            KeyValue* current = table[i];
            while (current) {
                KeyValue* temp = current;
                current = current->next;
                delete temp;
            }
        }
    }
};

int main() {
    HashMap map;
    string key;
    int value;
    int choice;

    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Insert key-value pair" << endl;
        cout << "2. Look up value by key" << endl;
        cout << "3. Delete key-value pair" << endl;
        cout << "4. Display the hash map" << endl;
        cout << "5. Quit" << endl;
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cerr << "Invalid input. Please enter a valid option." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1:
                cout << "Enter key: ";
                if (!(cin >> key)) {
                    cerr << "Invalid input. Please enter a valid key." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
                cout << "Enter value: ";
                if (!(cin >> value)) {
                    cerr << "Invalid input. Please enter a valid value." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
                map.insert(key, value);
                break;
            case 2:
                cout << "Enter key to look up its value: ";
                if (!(cin >> key)) {
                    cerr << "Invalid input. Please enter a valid key." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
                value = map.lookup(key);
                if (value != -1) {
                    cout << "Value for key '" << key << "' is " << value << endl;
                } else {
                    cout << "Key '" << key << "' not found in the hash map" << endl;
                }
                break;
            case 3:
                cout << "Enter key to delete: ";
                if (!(cin >> key)) {
                    cerr << "Invalid input. Please enter a valid key." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
                map.deleteKey(key);
                cout << "Key '" << key << "' deleted from the hash map" << endl;
                break;
            case 4:
                map.displayHashMap();
                break;
            case 5:
                map.cleanupHashMap();
                return 0;
            default:
                cerr << "Invalid choice. Please select a valid option." << endl;
        }
    }
}
