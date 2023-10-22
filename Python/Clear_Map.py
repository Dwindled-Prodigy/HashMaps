def clear(self):
    for i in range(self.TABLE_SIZE):
        current = self.table[i]
        while current:
            temp = current
            current = current.next
            del temp
        self.table[i] = None
