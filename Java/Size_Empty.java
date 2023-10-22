public int getSize() {
    int size = 0;
    for (int i = 0; i < TABLE_SIZE; i++) {
        KeyValue current = table[i];
        while (current != null) {
            size++;
            current = current.next;
        }
    }
    return size;
}

public boolean isEmpty() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i] != null) {
            return false; // Not empty
        }
    }
    return true; // Empty
}
