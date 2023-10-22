import java.util.HashMap;
import java.util.Scanner;

public class HashMapExample {
    public static void main(String[] args) {
        HashMap<String, Integer> hashMap = new HashMap<>();
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.println("Menu:");
            System.out.println("1. Insert key-value pair");
            System.out.println("2. Look up value by key");
            System.out.println("3. Delete key-value pair");
            System.out.println("4. Quit");
            System.out.print("Enter your choice: ");

            int choice = scanner.nextInt();
            scanner.nextLine();

            switch (choice) {
                case 1:
                    System.out.print("Enter key: ");
                    String key = scanner.nextLine();
                    System.out.print("Enter value: ");
                    int value = scanner.nextInt();
                    hashMap.put(key, value);
                    break;
                case 2:
                    System.out.print("Enter key to look up its value: ");
                    key = scanner.nextLine();
                    if (hashMap.containsKey(key)) {
                        System.out.println("Value for key '" + key + "' is " + hashMap.get(key));
                    } else {
                        System.out.println("Key '" + key + "' not found in the hash map");
                    }
                    break;
                case 3:
                    System.out.print("Enter key to delete: ");
                    key = scanner.nextLine();
                    if (hashMap.containsKey(key)) {
                        hashMap.remove(key);
                        System.out.println("Key '" + key + "' deleted from the hash map");
                    } else {
                        System.out.println("Key '" + key + "' not found in the hash map");
                    }
                    break;
                case 4:
                    scanner.close();
                    return;
                default:
                    System.out.println("Invalid choice. Please select a valid option.");
            }
        }
    }
}
