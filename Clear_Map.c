void clearHashMap(HashMap* map) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        KeyValue* current = map->table[i];
        while (current) {
            KeyValue* temp = current;
            current = current->next;
            free(temp->key);
            free(temp);
        }
        map->table[i] = NULL;
    }
}
