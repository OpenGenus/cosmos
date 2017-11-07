// Part of Cosmos by OpenGenus Foundation

import java.util.Arrays;

public class divided_differences {
    
    private static void divided_diff(double[][] matrix, int sLength) {
        int i = 1, i2 = 2, j = 2, s2 = sLength;
        for (int z = 0; z < sLength - 1; z++, j++, s2 -= 1, i2++) {
            for (int y = 0; y < s2 - 1; y++, i += 2) {
                matrix[i][j] = (matrix[i + 1][j - 1] - matrix[i - 1][j - 1])
                        / (matrix[i + (i2 - 1)][0] - matrix[i - (i2 - 1)][0]);
            }
            i = i2;
        }
    }

    public static void main(String[] args) {
        Double[] commonValues = {1.0, 2.0, 3.0, 4.0};
        Double[] commonFunValues = {1.0, 8.0, 27.0, 64.0};
        int length = commonValues.length;

        double[][] mas = new double[(2 * length) - 1][length + 1];
        for (int i = 0, z = 0; i < length; i++, z += 2) {
            mas[z][0] = commonValues[i];
            mas[z][1] = commonFunValues[i];
        }

        divided_diff(mas, length);

        for (int q = 0; q < length * 2 - 1; q++) {
            System.out.println(Arrays.toString(mas[q]));
        }
    }
}