// Part of Cosmos by OpenGenus Foundation

import java.util.Scanner;

public class pascal_triangle {

    private static Integer[][] PascalTriangle(int n) {
        Integer[][] matrix = new Integer[n][n];
        for (int i = 0; i < n; ++i) {
            matrix[i][0] = matrix[i][i] = 1;
            for (int f = 1; f < i; ++f) {
                matrix[i][f] = matrix[i - 1][f - 1] + matrix[i - 1][f];
            }
        }
        return matrix;
    }

    public static void main(String[] args) {
        System.out.print("Enter number of rows: ");
        Scanner valEnter = new Scanner(System.in);
        int value = valEnter.nextInt();
        value++;
        Integer[][] mas = PascalTriangle(value);

        //Beautiful output
        for (int q = 0; q < value; q++) {
            for (int k = 0; k <= q; k++) {
                System.out.format("%d", mas[q][k]);
                System.out.print(" ");
            }
            System.out.println();
        }
    }
} 
