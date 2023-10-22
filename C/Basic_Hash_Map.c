#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 1000

typedef struct KeyValue {
    char* key;
    int value;
    struct KeyValue* next;
} KeyValue;

typedef struct HashMap {
    KeyValue* table[TABLE_SIZE];
} HashMap;

unsigned int hash(const char* key) {
    unsigned int hash = 0;
    while (*key) {
        hash = (hash * 31) + (*key);
        key++;
    }
    return hash % TABLE_SIZE;
}

KeyValue* createKeyValue(const char* key, int value) {
    KeyValue* kv = (KeyValue*)malloc(sizeof(KeyValue));
    if (!kv) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    kv->key = strdup(key);
    if (!kv->key) {
        perror("Memory allocation failed");
        free(kv);
        exit(EXIT_FAILURE);
    }
    kv->value = value;
    kv->next = NULL;
    return kv;
}

void insert(HashMap* map, const char* key, int value) {
    unsigned int index = hash(key);
    KeyValue* newKeyValue = createKeyValue(key, value);
    newKeyValue->next = map->table[index];
    map->table[index] = newKeyValue;
}

int lookup(HashMap* map, const char* key) {
    unsigned int index = hash(key);
    KeyValue* current = map->table[index];
    while (current) {
        if (strcmp(current->key, key) == 0) {
            return current->value;
        }
        current = current->next;
    }
    return -1; // Key not found
}

void deleteKey(HashMap* map, const char* key) {
    unsigned int index = hash(key);
    KeyValue* current = map->table[index];
    KeyValue* prev = NULL;

    while (current) {
        if (strcmp(current->key, key) == 0) {
            if (prev == NULL) {
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

void displayHashMap(const HashMap* map) {
    printf("Hash Map Contents:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        KeyValue* current = map->table[i];
        if (current) {
            while (current) {
                printf("  Key: %s, Value: %d\n", current->key, current->value);
                current = current->next;
            }
        }
    }
}

void cleanupHashMap(HashMap* map) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        KeyValue* current = map->table[i];
        while (current) {
            KeyValue* temp = current;
            current = current->next;
            free(temp->key);
            free(temp);
        }
    }
}

int main() {
    HashMap map;
    for (int i = 0; i < TABLE_SIZE; i++) {
        map.table[i] = NULL;
    }

    char key[50];
    int value;
    int choice;

    while (1) {
        printf("Menu:\n");
        printf("1. Insert key-value pair\n");
        printf("2. Look up value by key\n");
        printf("3. Delete key-value pair\n");
        printf("4. Display the hash map\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            fprintf(stderr, "Invalid input. Please enter a valid option.\n");
            while (getchar() != '\n');  // Clear the input buffer
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter key: ");
                if (scanf("%s", key) != 1) {
                    fprintf(stderr, "Invalid input. Please enter a valid key.\n");
                    while (getchar() != '\n');  // Clear the input buffer
                    continue;
                }
                printf("Enter value: ");
                if (scanf("%d", &value) != 1) {
                    fprintf(stderr, "Invalid input. Please enter a valid value.\n");
                    while (getchar() != '\n');  // Clear the input buffer
                    continue;
                }
                insert(&map, key, value);
                break;
            case 2:
                printf("Enter key to look up its value: ");
                if (scanf("%s", key) != 1) {
                    fprintf(stderr, "Invalid input. Please enter a valid key.\n");
                    while (getchar() != '\n');  // Clear the input buffer
                    continue;
                }
                int result = lookup(&map, key);
                if (result != -1) {
                    printf("Value for key '%s' is %d\n", key, result);
                } else {
                    printf("Key '%s' not found in the hash map\n", key);
                }
                break;
            case 3:
                printf("Enter key to delete: ");
                if (scanf("%s", key) != 1) {
                    fprintf(stderr, "Invalid input. Please enter a valid key.\n");
                    while (getchar() != '\n');  // Clear the input buffer
                    continue;
                }
                deleteKey(&map, key);
                printf("Key '%s' deleted from the hash map\n", key);
                break;
            case 4:
                displayHashMap(&map);
                break;
            case 5:
                cleanupHashMap(&map);
                return 0;
            default:
                fprintf(stderr, "Invalid choice. Please select a valid option.\n");
        }
    }
}
