// Part of Cosmos by OpenGenus Foundation

import java.math.BigDecimal;
import java.util.ArrayList;

public class LagrangePolynomial {

    private static ArrayList<Double> middleFun = new ArrayList<>();

    public static void main(String[] args) {
        Double[] commonX = {1.0, 2.0, 3.0, 4.0};
        Double[] commonFun = {1.0, 8.0, 27.0, 64.0};
        Double[] middleX = {1.5, 2.5, 3.5};

        basicLagrangePolynomial(commonFun, commonX, middleX);

        System.out.println(middleFun);
    }

    private static void basicLagrangePolynomial(Double[] commonFunValues, Double[] commonPoints, Double[] middlePoints) {
        for (int importantX = 0; importantX <= middlePoints.length - 1; importantX++) {
            double number = middlePoints[importantX];
            double example;
            //Counters, so that x does not match when subtracting the numerators.
            int countA = 0;
            int countB = 0;
            double comp3 = 0;
            for (int q = 0; q <= commonFunValues.length - 1; q++) {
                double comp = 1;
                double comp2 = 1;
                double function = commonFunValues[q];
                for (int a = 0; a <= commonPoints.length - 1; a++) {
                    example = commonPoints[a];
                    if (countA != a) {
                        comp = comp * (number - example);
                    } else {
                        for (int b = 0; b <= commonPoints.length - 1; b++) {
                            double nextN = commonPoints[b];
                            if (countB != b) {
                                comp2 = comp2 * (example - nextN);
                            }
                        }
                    }
                }
                comp3 = comp3 + function * (comp / comp2);
                countA++;
                countB++;
            }
            //Rounding off values for perfect view
            BigDecimal test = new BigDecimal(comp3);
            String round = test.setScale(3, BigDecimal.ROUND_HALF_EVEN).toString();
            double comp3Out;
            comp3Out = Double.parseDouble(round);
            middleFun.add(comp3Out);
        }
    }
}
