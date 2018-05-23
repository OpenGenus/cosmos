import java.util.Scanner;

public final class CaesarCipher {
    private final static int MIN_KEY = 1;
    private final static int MAX_KEY = 26;

    public static void main(String[] args){
        final Scanner scanner = new Scanner(System.in);
        String ans = "";

        System.out.print("Enter a message: ");
        String message = scanner.nextLine();

        System.out.print("Encrypt or Decrypt: ");
        char type = scanner.next().charAt(0);
        int key = 0;

        do {
            System.out.print("Enter a key: ");
            key = scanner.nextInt();
        } while (key < MIN_KEY || key > MAX_KEY);
        
        key = (type == 'd' || type == 'D') ? -key : key;

        for (char c : message.toCharArray()) {
            int num = (int) c;

            if (Character.isAlphabetic(c)) {
                num += key;
                if (Character.isUpperCase(c)) {
                    if (num > 'Z') {
                        num -= MAX_KEY;
                    }
                    else if (num < 'A') {
                        num += MAX_KEY;
                    }
                }
                else if (Character.isLowerCase(c)) {
                    if (num > 'z') {
                        num -= MAX_KEY;
                    }
                    else if (num < 'a') {
                        num += MAX_KEY;
                    }
                }
            }

            ans += (char) num;
        }

        System.out.println(ans);
    }
}
