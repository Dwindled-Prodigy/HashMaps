int getSize() const {
    int size = 0;
    for (int i = 0; i < TABLE_SIZE; i++) {
        KeyValue* current = table[i];
        while (current) {
            size++;
            current = current->next;
        }
    }
    return size;
}

bool isEmpty() const {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i] != nullptr) {
            return false; // Not empty
        }
    }
    return true; // Empty
}
