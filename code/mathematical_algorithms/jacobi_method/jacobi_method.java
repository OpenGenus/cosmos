/* Part of Cosmos by OpenGenus Foundation */

import java.math.BigDecimal;
import java.math.RoundingMode;
import java.util.Arrays;

public class JacobiMethod {
    private static double e = 0.01;

    private static void methodJacobi(double[][] matrix, int rows, int cols) {
        double lastCommonSum = 0;   //Sum initial approximation
        Double[] initAp = new Double[rows];
        //Get Initial Approximation
        for (int i = 0; i < (cols - 1); i++) {
            double divider = matrix[i][i];
            double temp = matrix[i][cols - 1] / divider;
            temp = new BigDecimal(temp).setScale(2, RoundingMode.HALF_UP).doubleValue();
            lastCommonSum = lastCommonSum + temp;
            initAp[i] = temp;
        }
        Double[] tempMassive = new Double[rows];
        System.out.println("Start Jacobi method's");
        double[][] tempMatrix = new double[rows][cols];
        double compare = 1;
        int f = 0;
        while (Math.abs(compare) > e) {
            double commonSum = 0;   //Sum next approximation
            copyMatrix(tempMatrix, matrix);
            for (int i = 0; i < (cols - 1); i++) {
                double sum = 0, lastN = 0;
                for (int ip = 0; ip < (cols); ip++) {
                    if (ip == i) {
                        lastN = tempMatrix[i][ip];
                        sum = sum + tempMatrix[i][cols - 1];
                    } else if (ip != cols - 1) {
                        double temp = tempMatrix[i][ip] * initAp[ip] * -1;
                        tempMatrix[i][ip] = new BigDecimal(temp).setScale(6, RoundingMode.HALF_UP).doubleValue();
                        sum = sum + temp;
                    } else {
                        sum = sum / lastN;
                    }
                }
                sum = new BigDecimal(sum).setScale(6, RoundingMode.HALF_UP).doubleValue();
                commonSum = commonSum + sum;
                tempMassive[i] = sum;   //massive new values apprx
            }
            System.out.println("For f:" + f + " = " + Arrays.toString(tempMassive) +
                    " Last sum: " + lastCommonSum + " next sum: " + commonSum);
            f++;
            compare = commonSum - lastCommonSum;    //Difference last and next values
            initAp = tempMassive;
            lastCommonSum = commonSum;
        }

    }
    
    private static void printArray(double[][] arr, int rows, int cols) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                System.out.print(arr[i][j] + " ");
            }
            System.out.println();
        }
        System.out.println();
    }

    private static void copyMatrix(double[][] a, double[][] b) {
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < a[0].length; j++) {
                a[i][j] = b[i][j];
            }
        }
    }

    public static void main(String[] args) {
        double[][] myMatrix = {
                {20.9, 1.2, 2.1, 0.9, 21.70},
                {1.2, 21.2, 1.5, 2.5, 27.46},
                {2.1, 1.5, 19.8, 1.3, 28.76},
                {0.9, 2.5, 1.3, 32.1, 49.72}};
        System.out.println("Original matrix: ");
        printArray(myMatrix, 4, 5);
        methodJacobi(myMatrix, 4, 5);
    }
}