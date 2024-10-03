import java.util.Scanner;
import java.util.regex.*;

public class RunningKey {

    private static final Scanner scan = new Scanner(System.in);
    private static final int ALPHABET_SIZE = 26;
    private static final String regex = "[A-Za-z]+$";

    public static void main(String[] args) {
        boolean validCode = false;
        do {
            print("Type '1' for encryption, '2' for decryption, 'exit' for exit program and press enter. >> ");
            String input = scan.nextLine();
            if (input.equalsIgnoreCase("exit")) {
                println("Exit program...");
                return;
            }
            short type = tryParse(input, (short)-1);
            validCode = true;
            switch (type) {
            case 1:
                encryptionWrapper();
                break;
            case 2:
                decryptionWrapper();
                break;
            default:
                validCode = false;
                println("Invalid code, please try again.");
                break;
            }
        } while (validCode == false);
    }

    private static void print(String message) {
        System.out.print(message);
    }

    private static void println(String message) {
        System.out.println(message);
    }

    private static short tryParse(String value, short defaultValue) {
        try {
            return Short.parseShort(value);
        } catch (NumberFormatException e) {
            return defaultValue;
        }
    }

    private static void encryptionWrapper() {
        boolean isValid = true;
        do {
            print("Enter plaintext which you want to encrypt >> ");
            String plainText = scan.nextLine();
            print("Enter key with size equal plaintext >> ");
            String key = scan.nextLine();

            // Validate
            if (Pattern.matches(regex, plainText) == false || Pattern.matches(regex, key) == false) {
                isValid = false;
                println("** Plaintext/key invalid, must contain only alphabet, not number not punctuation, please try again **");
            } else if (plainText.length() != key.length()) {
                isValid = false;
                println("** Size of plaintext and key must equal, please try again **");
            } else {
                isValid = true;
                encrypt(plainText, key);
            }
        } while (isValid == false);
    }

    private static void encrypt(String plaintext, String key) {
        plaintext = plaintext.toLowerCase();
        key = key.toLowerCase();
        String cipherText = "";

        for (int i = 0; i < plaintext.length(); ++i) {
            char a = plaintext.charAt(i);
            char b = key.charAt(i);
            int result = (((int)a - 97) + ((int)b - 97)) % ALPHABET_SIZE + 97;
            char cipherChar = (char)result;
            cipherText += String.valueOf(cipherChar);
        }
        print("Ciphertext : " + cipherText);
    }

    private static void decryptionWrapper() {
        boolean isValid = true;
        do {
            print("Enter ciphertext which you want to decrypt >> ");
            String ciphertext = scan.nextLine();
            print("Enter key with size equal ciphertext >> ");
            String key = scan.nextLine();

            // Validate
            if (Pattern.matches(regex, ciphertext) == false || Pattern.matches(regex, key) == false) {
                isValid = false;
                println("** Ciphertext/key invalid, must contain only alphabet, not number not punctuation, please try again **");
            } else if (ciphertext.length() != key.length()) {
                isValid = false;
                println("** Size of ciphertext and key must equal, please try again **");
            } else {
                isValid = true;
                decrypt(ciphertext, key);
            }
        } while (isValid == false);
    }

    private static void decrypt(String ciphertext, String key) {
        ciphertext = ciphertext.toLowerCase();
        key = key.toLowerCase();
        String plaintext = "";

        for (int i = 0; i < ciphertext.length(); ++i) {
            char a = ciphertext.charAt(i);
            char b = key.charAt(i);
            int result = (ALPHABET_SIZE + ((int)a - 97) - ((int)b - 97)) % ALPHABET_SIZE + 97;
            char plainChar = (char)result;
            plaintext += String.valueOf(plainChar);
        }
        print("Plaintext : " + plaintext);
    }
}
