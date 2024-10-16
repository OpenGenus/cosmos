import java.util.Scanner;

/**
 * Created by Phuwarin on 10/23/2017.
 */
public class Affine {

    private static final Scanner SCANNER = new Scanner(System.in);
    private static final int ALPHABET_SIZE = 26;

    public static void main(String[] args) {

        System.out.print("Type 1 for encryption and 2 for decryption then Enter >> ");
        int command = getCommand();
        switch (command) {
            case 1:
                encryption();
                break;
            case 2:
                decryption();
                break;
            default:
                System.out.println("Command error, pls try again.");
                main(null);
        }
    }

    private static void decryption() {
        int a, aInverse = 0, b;
        boolean isAOk = false;

        System.out.print("Enter ciphertext which want to decryption >> ");
        String ciphertext = SCANNER.next();

        while (!isAOk) {
            System.out.print("Enter key 'a' >> ");
            a = SCANNER.nextInt();
            if (gcd(a, ALPHABET_SIZE) == 1) {
                isAOk = true;
                aInverse = findInverse(a, ALPHABET_SIZE);
            } else {
                System.out.println("'a' is not ok, pls try again.");
            }
        }

        System.out.print("Enter key 'b' >> ");
        b = SCANNER.nextInt();

        decrypt(aInverse, b, ciphertext);
    }

    private static void decrypt(int aInverse, int b, String ciphertext) {
        if (ciphertext == null || ciphertext.length() <= 0) {
            System.out.println("Plaintext has a problem. Bye bye :)");
            return;
        }

        ciphertext = ciphertext.toLowerCase();
        StringBuilder plaintext = new StringBuilder();
        int z, j;

        for (int i = 0; i < ciphertext.length(); i++) {
            char agent = ciphertext.charAt(i);
            z = aInverse * ((agent - 97) - b);
            j = z < 0 ? minusMod(z, ALPHABET_SIZE) : z % ALPHABET_SIZE;
            plaintext.append((char) ('A' + j));
        }
        System.out.println("Plaintext: " + plaintext);
    }

    private static int minusMod(int minus, int mod) {
        int a = Math.abs(minus);
        return (mod * ((a / mod) + 1)) - a;
    }

    private static int findInverse(double firstNumber, double anotherNumber) {
        int a1, b1, a2, b2, r, q, temp_a2, temp_b2, n1, n2, max;

        if (firstNumber > anotherNumber) {
            max = (int) firstNumber;
            n1 = (int) firstNumber;
            n2 = (int) anotherNumber;
        } else {
            max = (int) anotherNumber;
            n1 = (int) anotherNumber;
            n2 = (int) firstNumber;
        }

        a1 = b2 = 1;
        b1 = a2 = 0;
        temp_a2 = a2;
        temp_b2 = b2;

        r = n1 % n2;
        q = n1 / n2;

        while (r != 0) {
            n1 = n2;
            n2 = r;
            a2 = a1 - q * a2;
            b2 = b1 - q * b2;
            a1 = temp_a2;
            b1 = temp_b2;
            temp_a2 = a2;
            temp_b2 = b2;
            r = n1 % n2;
            q = n1 / n2;
        }

        int result;
        if (firstNumber == max) {
            if (a2 < 0) {
                result = (int) (a2 - anotherNumber * Math.floor(a2 / anotherNumber));
            } else {
                result = a2;
            }
        } else {
            if (b2 < 0) {
                result = (int) (b2 - anotherNumber * Math.floor(b2 / anotherNumber));
            } else
                result = b2;
        }
        return result;
    }

    private static void encryption() {
        boolean isAOk = false, isBOk = false;
        int a = 0, b = 0;

        System.out.print("Enter plaintext which want to encryption >> ");
        String plaintext = SCANNER.next();

        while (!isAOk) {
            System.out.print("Choose 'a' but gcd (a,26) must equal 1\n" +
                    "'a' might be {1, 3, 5, 7, 9, 11, 15, 17, 19, 21, 23, 25} >> ");
            a = SCANNER.nextInt();
            if (gcd(a, ALPHABET_SIZE) == 1) {
                isAOk = true;
            } else {
                System.out.println("'a' is not ok, pls try again.");
            }
        }

        while (!isBOk) {
            System.out.print("Choose 'b' which number you want but not equal 1 >> ");
            b = SCANNER.nextInt();
            if (b != 1) {
                isBOk = true;
            } else {
                System.out.println("'b' is not ok, pls try again.");
            }
        }
        encrypt(a, b, plaintext);
    }

    private static int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    private static int getCommand() {
        return SCANNER.nextInt();
    }

    private static void encrypt(int a, int b, String plaintext) {
        if (plaintext == null || plaintext.length() <= 0) {
            System.out.println("Plaintext has a problem. Bye bye :)");
            return;
        }

        plaintext = plaintext.toLowerCase();
        StringBuilder ciphertext = new StringBuilder();

        for (int i = 0; i < plaintext.length(); i++) {
            char agent = plaintext.charAt(i);
            int value = ((a * (agent - 97) + b) % ALPHABET_SIZE);
            ciphertext.append((char) (value + 97));
        }
        System.out.println("Ciphertext: " + ciphertext);
    }
}
