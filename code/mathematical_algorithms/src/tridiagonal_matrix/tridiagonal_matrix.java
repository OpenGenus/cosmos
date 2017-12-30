public class TridiagonalMatrix {
    private static void TridiagonalMatrix(double matrix[][], int rows, int cols) {
        double[][] output = new double[rows][cols + 1];
        System.out.println("First step:");
        //Initialization of initial values for subsequent cycles.
        double y1 = matrix[0][0];
        double alpha = -matrix[0][1] / y1;
        alpha = new BigDecimal(alpha).setScale(2, RoundingMode.HALF_DOWN).doubleValue();
        double betta = matrix[0][cols - 1] / y1;
        betta = new BigDecimal(betta).setScale(2, RoundingMode.HALF_DOWN).doubleValue();
        //Future alpha
        double alphaNext;
        //Calculating count for alpha, the next string it ++ to find needing alpha.
        int countA = 0;
        int countC = 2;
        output[0][0] = y1;
        output[1][0] = alpha;
        output[0][1] = betta;
        output[0][cols] = matrix[0][cols - 1];
        for (int i = 1; i < cols - 1; i++) {
            double b_i = matrix[i][i];
            double alhpa_i = matrix[i][countA];
            alhpa_i = new BigDecimal(alhpa_i).setScale(2, RoundingMode.HALF_DOWN).doubleValue();
            double y_i = b_i + alhpa_i * alpha;
            y_i = new BigDecimal(y_i).setScale(2, RoundingMode.HALF_DOWN).doubleValue();
            if (countC < cols - 1) {
                //Count second alpha for future
                alphaNext = -matrix[i][countC] / y_i;
                alphaNext = new BigDecimal(alphaNext).setScale(2, RoundingMode.HALF_DOWN).doubleValue();
                output[countC][i] = alphaNext;
            } else {
                alphaNext = 1;
            }
            double betta_i = (matrix[i][cols - 1] - alhpa_i * betta) / y_i;
            betta_i = new BigDecimal(betta_i).setScale(2, RoundingMode.HALF_DOWN).doubleValue();
            output[i][i] = y_i;
            output[i][countC] = betta_i;
            output[i][cols] = matrix[i][cols - 1];
            countA++;
            countC++;
            alpha = alphaNext;
            betta = betta_i;
        }
        printArray(output, rows, cols+1);
        System.out.println("Second step:");

        ArrayList<Double> arrayList = new ArrayList<>();
        //Find the last element Betta
        double x = output[rows - 1][cols - 1];
        int countAlpha = rows - 1;
        int countBetta = rows - 1;
        arrayList.add(x);
        for (int j = cols - 2; j > 0; j--) {
            double alpha_i = output[countAlpha][j - 1];
            double x_i = alpha_i * x + output[countBetta - 1][j];
            x_i = new BigDecimal(x_i).setScale(2, RoundingMode.HALF_DOWN).doubleValue();
            arrayList.add(x_i);
            x = x_i;
            countAlpha--;
            countBetta--;
        }
        System.out.println(arrayList);
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

    public static void main(String[] args) {
        double[][] myMatrix = {{9.0, 5.0, 0.0, 0.0, 0.0, 4.0}, {3.0, 7.0, 1.0, 0.0, 0.0, 4.0}, {0.0, 5.0, 11.0, 2.0, 0.0, 4.0}, {0.0, 0.0, 5.0, 6.0, 4.0, 4.0}, {0.0, 0.0, 0.0, 4.0, 5.0, 2.0}};
        int rows = myMatrix.length;
        int cols = myMatrix[2].length;
        System.out.println("Original matrix: ");
        printArray(myMatrix, rows, cols);
        TridiagonalMatrix(myMatrix, rows, cols);
    }
}