#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the hash table
#define TABLE_SIZE 100

// Structure for a key-value pair
typedef struct KeyValue {
    char* key;
    int value;
    struct KeyValue* next;
} KeyValue;

// Structure for the hash map
typedef struct HashMap {
    KeyValue* table[TABLE_SIZE];
} HashMap;

// Hash function to generate an index from a key
unsigned int hash(const char* key) {
    unsigned int hash = 0;
    while (*key) {
        hash = (hash * 31) + (*key);
        key++;
    }
    return hash % TABLE_SIZE;
}

// Function to create a new key-value pair
KeyValue* createKeyValue(const char* key, int value) {
    KeyValue* kv = (KeyValue*)malloc(sizeof(KeyValue));
    kv->key = strdup(key);
    kv->value = value;
    kv->next = NULL;
    return kv;
}

// Function to insert a key-value pair into the hash map
void insert(HashMap* map, const char* key, int value) {
    unsigned int index = hash(key);
    KeyValue* newKeyValue = createKeyValue(key, value);

    // Add the new key-value pair to the beginning of the linked list
    newKeyValue->next = map->table[index];
    map->table[index] = newKeyValue;
}

// Function to look up a value by key in the hash map
int lookup(HashMap* map, const char* key) {
    unsigned int index = hash(key);
    KeyValue* current = map->table[index];
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return current->value;
        }
        current = current->next;
    }
    return -1; // Key not found
}

// Function to delete a key-value pair from the hash map
void deleteKey(HashMap* map, const char* key) {
    unsigned int index = hash(key);
    KeyValue* current = map->table[index];
    KeyValue* prev = NULL;

    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            if (prev == NULL) {
                // If the key to be deleted is the first in the list
                map->table[index] = current->next;
            } else {
                prev->next = current->next;
            }
            free(current->key);
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

int main() {
    HashMap map;
    for (int i = 0; i < TABLE_SIZE; i++) {
        map.table[i] = NULL;
    }

    char key[50];
    int value;

    while (1) {
        printf("Menu:\n");
        printf("1. Insert key-value pair\n");
        printf("2. Look up value by key\n");
        printf("3. Delete key-value pair\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key: ");
                scanf("%s", key);
                printf("Enter value: ");
                scanf("%d", &value);
                insert(&map, key, value);
                break;
            case 2:
                printf("Enter key to look up its value: ");
                scanf("%s", key);
                int result = lookup(&map, key);
                if (result != -1) {
                    printf("Value for key '%s' is %d\n", key, result);
                } else {
                    printf("Key '%s' not found in the hash map\n", key);
                }
                break;
            case 3:
                printf("Enter key to delete: ");
                scanf("%s", key);
                deleteKey(&map, key);
                printf("Key '%s' deleted from the hash map\n", key);
                break;
            case 4:
                // Clean up memory (free dynamically allocated memory)
                for (int i = 0; i < TABLE_SIZE; i++) {
                    KeyValue* current = map.table[i];
                    while (current != NULL) {
                        KeyValue* temp = current;
                        current = current->next;
                        free(temp->key);
                        free(temp);
                    }
                }
                return 0;
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    }
}
