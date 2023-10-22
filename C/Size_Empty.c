int getSize(const HashMap* map) {
    int size = 0;
    for (int i = 0; i < TABLE_SIZE; i++) {
        KeyValue* current = map->table[i];
        while (current) {
            size++;
            current = current->next;
        }
    }
    return size;
}

int isEmpty(const HashMap* map) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (map->table[i] != NULL) {
            return 0; // Not empty
        }
    }
    return 1; // Empty
}
