def main():
    hashmap = {}
    
    while True:
        print("Menu:")
        print("1. Insert key-value pair")
        print("2. Look up value by key")
        print("3. Delete key-value pair")
        print("4. Display the hash map")
        print("5. Quit")
        choice = input("Enter your choice: ")
        
        if not choice.isdigit():
            print("Invalid input. Please enter a valid option.")
            continue
        
        choice = int(choice)

        if choice == 1:
            key = input("Enter key: ")
            value = input("Enter value: ")
            try:
                hashmap[key] = int(value)
            except ValueError:
                print("Invalid input. Please enter a valid value.")
        elif choice == 2:
            key = input("Enter key to look up its value: ")
            value = hashmap.get(key, -1)
            if value != -1:
                print(f"Value for key '{key}' is {value}")
            else:
                print(f"Key '{key}' not found in the hash map")
        elif choice == 3:
            key = input("Enter key to delete: ")
            if key in hashmap:
                del hashmap[key]
                print(f"Key '{key}' deleted from the hash map")
            else:
                print(f"Key '{key}' not found in the hash map")
        elif choice == 4:
            print("Hash Map Contents:")
            for key, value in hashmap.items():
                print(f"Key: {key}, Value: {value}")
        elif choice == 5:
            break
        else:
            print("Invalid choice. Please select a valid option.")

if __name__ == "__main__":
    main()
