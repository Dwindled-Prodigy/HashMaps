public void clear() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        KeyValue current = table[i];
        while (current != null) {
            KeyValue temp = current;
            current = current.next;
            table[i] = null;
            delete temp;
        }
        table[i] = null;
    }
}
