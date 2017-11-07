import java.util.Scanner;

public final class perfect_number {
    private static boolean hasPerfect = false;

    public static void main(String[] args){
        final Scanner scanner = new Scanner(System.in);

        System.out.print("Enter a number: ");
        int number = scanner.nextInt();

        for (int i = 6; i < number; i++) {
            if (isPerfect(i)) {
                System.out.println(i + " is a perfect number.");
                hasPerfect = true;
            }
        }

        if (!hasPerfect) {
            System.out.println("No perfect numbers found.");
        }
    }

    private final static boolean isPerfect(final int number) {
        int sum = 0;

        for (int i = 1; i < number - 1; i++) {
            int rem = number % i;

            if (rem == 0) {
                sum += i;
            }
        }

        return sum == number;
    }
}
