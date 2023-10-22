void clear() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        KeyValue* current = table[i];
        while (current) {
            KeyValue* temp = current;
            current = current->next;
            delete temp;
        }
        table[i] = nullptr;
    }
}
