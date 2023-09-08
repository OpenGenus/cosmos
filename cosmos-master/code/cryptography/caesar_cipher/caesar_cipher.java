import java.lang.StringBuilder;
import java.util.Scanner;

public final class caesar_cipher {
    private final static int MIN_KEY = 1;
    private final static int MAX_KEY = 26;

    public static void main(String[] args){
        final Scanner scanner = new Scanner(System.in);
        final StringBuilder sb = new StringBuilder();

        System.out.print("Enter a message: ");
        String message = scanner.nextLine();

        System.out.print("Encrypt or Decrypt: ");
        char type = scanner.next().charAt(0);

        System.out.print("Enter a key: ");
        int key = (type == 'd' || type == 'D') ? -scanner.nextInt() : scanner.nextInt();

        if (Math.abs(key) < MIN_KEY || Math.abs(key) > MAX_KEY) {
            System.out.println("Key out of bounds.");
            System.exit(1);
        }

        message.chars().forEach(c -> {
            int num = (int) c;

            if (Character.isAlphabetic(c)) {
                num += key;

                if (Character.isUpperCase(c)) {
                    if (c > 'Z') {
                        num -= MAX_KEY;
                    }
                    else if (c < 'A') {
                        num += MAX_KEY;
                    }
                }
                else if (Character.isLowerCase(c)) {
                    if (c > 'z') {
                        num -= MAX_KEY;
                    }
                    else if (c < 'a') {
                        num += MAX_KEY;
                    }
                }
            }

            sb.append((char)num);
        });

        System.out.println(sb.toString());
    }
}
