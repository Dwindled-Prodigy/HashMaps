def get_size(self):
    size = 0
    for i in range(self.TABLE_SIZE):
        current = self.table[i]
        while current:
            size += 1
            current = current.next
    return size

def is_empty(self):
    for i in range(self.TABLE_SIZE):
        if self.table[i] is not None:
            return False  # Not empty
    return True  # Empty
