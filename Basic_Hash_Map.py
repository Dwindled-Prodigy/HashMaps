hash_map = {}

while True:
    print("Menu:")
    print("1. Insert key-value pair")
    print("2. Look up value by key")
    print("3. Delete key-value pair")
    print("4. Quit")

    choice = int(input("Enter your choice: "))

    if choice == 1:
        key = input("Enter key: ")
        value = int(input("Enter value: "))
        hash_map[key] = value
    elif choice == 2:
        key = input("Enter key to look up its value: ")
        if key in hash_map:
            print(f"Value for key '{key}' is {hash_map[key}")
        else:
            print(f"Key '{key}' not found in the hash map")
    elif choice == 3:
        key = input("Enter key to delete: ")
        if key in hash_map:
            del hash_map[key]
            print(f"Key '{key}' deleted from the hash map")
        else:
            print(f"Key '{key}' not found in the hash map")
    elif choice == 4:
        break
    else:
        print("Invalid choice. Please select a valid option.")
      
