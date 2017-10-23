public class NewtonPolynomial {

    private static ArrayList<Double> output = new ArrayList<>();

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

    private static void newtonPolynomial(double[][] massive, int sLength) {
        ArrayList<Double> list = new ArrayList<>();
        int h = 1;
        for (int i = 0; i < (sLength * 2 - 1) / 2 + 1; i++) {
            for (int j = 1; j < 2; j++) {
                double g = massive[i][h];
                list.add(g);
            }
            h++;
        }

        for (int i = 0; i < (sLength * 2 - 1); i++) {
            System.out.println(Arrays.toString(massive[i]));
        }

        Double[] listMas = list.toArray(new Double[list.size()]);
        ArrayList<Double> arrPoints = new ArrayList<>();
        System.out.println();

        System.out.println(arrPoints);

        int m = 0;
        for (int i = 0; i < (sLength * 2 - 1) / 2 + 2; i++) {
            double q = massive[i][0];
            arrPoints.add(q);
            m++;
        }

        for (int g = 0; g < arrPoints.size(); g++) {
            if (arrPoints.get(g) == 0) {
                double temp = arrPoints.get(g);
                arrPoints.remove(g);
                arrPoints.add(temp);
            }
        }

        Double[] pointsX = arrPoints.toArray(new Double[arrPoints.size()]);

        for (double x = 1.5; x < 4; x++) {
            double sum = listMas[0];
            double peremen = 0;
            for (int i = 0; i < listMas.length; i++) {
                double predsum = 1;
                int sk = 0;
                if (sk != i) {
                    for (int j = 0; j < i; j++) {
                        predsum = predsum * (x - pointsX[j]);
                    }
                    peremen = listMas[i] * predsum;
                }
                sum = sum + peremen;
            }
            output.add(sum);
            System.out.println(sum);
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

        newtonPolynomial(mas, length);
        System.out.println(output);
    }
}
