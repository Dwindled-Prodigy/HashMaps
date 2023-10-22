#include <iostream>
#include <string>
#include <unordered_map>

int main() {
    std::unordered_map<std::string, int> hashMap;
    std::string key;
    int value;

    while (true) {
        std::cout << "Menu:\n";
        std::cout << "1. Insert key-value pair\n";
        std::cout << "2. Look up value by key\n";
        std::cout << "3. Delete key-value pair\n";
        std::cout << "4. Quit\n";
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter key: ";
                std::cin >> key;
                std::cout << "Enter value: ";
                std::cin >> value;
                hashMap[key] = value;
                break;
            case 2:
                std::cout << "Enter key to look up its value: ";
                std::cin >> key;
                if (hashMap.find(key) != hashMap.end()) {
                    std::cout << "Value for key '" << key << "' is " << hashMap[key] << std::endl;
                } else {
                    std::cout << "Key '" << key << "' not found in the hash map" << std::endl;
                }
                break;
            case 3:
                std::cout << "Enter key to delete: ";
                std::cin >> key;
                if (hashMap.find(key) != hashMap.end()) {
                    hashMap.erase(key);
                    std::cout << "Key '" << key << "' deleted from the hash map" << std::endl;
                } else {
                    std::cout << "Key '" << key << "' not found in the hash map" << std::endl;
                }
                break;
            case 4:
                return 0;
            default:
                std::cout << "Invalid choice. Please select a valid option." << std::endl;
        }
    }
}
