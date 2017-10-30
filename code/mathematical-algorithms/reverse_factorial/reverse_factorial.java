// Part of Cosmos by OpenGenus Foundation
public static String reverseFactorial(int n) {
    int number = n;
    int divisor = 2;
    while (number % divisor == 0) {
        number /= divisor;
        divisor++;
    }
    return String.format("%d = ", n) + ((divisor % number == 0) ? String.format("%d!", divisor - 1) : "NONE");
}
