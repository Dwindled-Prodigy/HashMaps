import java.util.Scanner;
import java.util.HashMap;

public class HashMapExample {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        HashMap<String, Integer> map = new HashMap<>();
        int choice;

        while (true) {
            System.out.println("Menu:");
            System.out.println("1. Insert key-value pair");
            System.out.println("2. Look up value by key");
            System.out.println("3. Delete key-value pair");
            System.out.println("4. Display the hash map");
            System.out.println("5. Quit");
            System.out.print("Enter your choice: ");

            if (!scanner.hasNextInt()) {
                System.err.println("Invalid input. Please enter a valid option.");
                scanner.nextLine();
                continue;
            }

            choice = scanner.nextInt();
            scanner.nextLine(); // Consume the newline character

            switch (choice) {
                case 1:
                    System.out.print("Enter key: ");
                    String key = scanner.nextLine();
                    System.out.print("Enter value: ");
                    if (!scanner.hasNextInt()) {
                        System.err.println("Invalid input. Please enter a valid value.");
                        scanner.nextLine();
                        continue;
                    }
                    int value = scanner.nextInt();
                    scanner.nextLine(); // Consume the newline character
                    map.put(key, value);
                    break;
                case 2:
                    System.out.print("Enter key to look up its value: ");
                    String lookupKey = scanner.nextLine();
                    Integer lookupValue = map.get(lookupKey);
                    if (lookupValue != null) {
                        System.out.println("Value for key '" + lookupKey + "' is " + lookupValue);
                    } else {
                        System.out.println("Key '" + lookupKey + "' not found in the hash map");
                    }
                    break;
                case 3:
                    System.out.print("Enter key to delete: ");
                    String deleteKey = scanner.nextLine();
                    if (map.remove(deleteKey) != null) {
                        System.out.println("Key '" + deleteKey + "' deleted from the hash map");
                    } else {
                        System.out.println("Key '" + deleteKey + "' not found in the hash map");
                    }
                    break;
                case 4:
                    System.out.println("Hash Map Contents:");
                    for (String mapKey : map.keySet()) {
                        int mapValue = map.get(mapKey);
                        System.out.println("Key: " + mapKey + ", Value: " + mapValue);
                    }
                    break;
                case 5:
                    scanner.close();
                    return;
                default:
                    System.err.println("Invalid choice. Please select a valid option.");
            }
        }
    }
}
