public class GaussianElimination {
    int rows;
    int cols;
    double[][] matrix;

    public GaussianElimination(double[][] matrix) {
        if (matrix == null) {
            throw new NullPointerException("matrix cannot be null");
        }
        this.rows = matrix.length;
        this.cols = matrix[0].length;
        this.matrix = new double[rows][cols];
        copyMatrix(this.matrix, matrix);
    }

    /*Row reduces our rows*cols=rows*(n+1) matrix into row reduced
    echelon form with Gaussian elimination. Where our matrix is a
    system of m equations with n variables.*/
    private void gaussianEliminate() {
        for (int i = 0; i < (cols - 1); i++) {
            System.out.println("Outer loop number: " + i);
            if (matrix[i][i] == 0) {
                boolean restColZero = true;
                int firstNonzeroRow = i;
                for (int ip = i; i < rows; ip++) {
                    if (matrix[ip][i] != 0) {
                        restColZero = false;
                        firstNonzeroRow = ip;
                        break;
                    }
                }
                if (restColZero) {
                    continue;
                } else {
                    swapRows(matrix, i, firstNonzeroRow);
                    System.out.println("Swapping rows " + i + " and " + firstNonzeroRow);
                }
            }
            double divider = matrix[i][i];
            System.out.println("Dividing row " + i + " by " + divider);
            printArray(matrix);
            for (int ip = 0; ip < (cols); ip++) {
                //Rounding for beautiful output but accuracy -0.1
                double temp = matrix[i][ip] / divider;
                double q = new BigDecimal(temp).setScale(1, RoundingMode.HALF_DOWN).doubleValue();
                matrix[i][ip]  = q;
            }
            for (int k = i + 1; k < rows; k++) {
                System.out.println("Subtracting " + matrix[k][i] + " times row " + i + " from row " + k);
                scaleSubtract(matrix, matrix[i], k, matrix[k][i]);
                printArray(matrix);
            }
        }
        System.out.println("Starting back substitution");
        for (int u = cols - 2; u >= 0; u--) {
            if (matrix[u][u] != 0) {
                for (int v = u - 1; v >= 0; v--) {
                    scaleSubtract(matrix, matrix[u], v, matrix[v][u]);
                    System.out.println("Subtracting " + matrix[v][u] + " times row " + u + " from row " + v);
                    printArray(matrix);
                }
            }
        }
    }

    /*Copies matrix b into matrix a*/
    private void copyMatrix(double[][] a, double[][] b) {
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < a[0].length; j++) {
                a[i][j] = b[i][j];
            }
        }
    }

    /*Swaps the rows rowNum and rowNump in a*/
    private void swapRows(double[][] a, int rowNum, int rowNump) {
        for (int i = 0; i < a.length; i++) {
            double temp = a[rowNum][i];
            a[rowNum][i] = a[rowNump][i];
            a[rowNump][i] = temp;
        }
    }

    /*Subtracts an array as a row from a at rowNum,
    with the array multiplied by factor*/
    private void scaleSubtract(double[][] a, double[] row, int rowNum, double factor) {
        for (int i = 0; i < cols; i++) {
            //Rounding for beautiful output but accuracy -0.1
            double temp = a[rowNum][i] - (row[i] * factor);
            double q = new BigDecimal(temp).setScale(1, RoundingMode.HALF_DOWN).doubleValue();
            a[rowNum][i] = q;
        }
    }

    public void printArray(double[][] arr) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                System.out.print(arr[i][j] + " ");
            }
            System.out.println();
        }
        System.out.println();
    }

    public static void main(String[] args) {
        double[][] myMatrix = {{3.0, 2.0, -5.0, -1.0}, {2.0, -1.0, 3.0, 13.0}, {1.0, 2.0, -1.0, 9.0}};
        GaussianElimination reducer = new GaussianElimination(myMatrix);
        System.out.println("Original matrix: ");
        reducer.printArray(reducer.matrix);
        reducer.gaussianEliminate();
        System.out.println("Result matrix: ");
        reducer.printArray(reducer.matrix);
    }
}
