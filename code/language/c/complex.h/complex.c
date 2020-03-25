/* Part of Cosmos by OpenGenus Foundation */
#include <stdio.h>      /* Standard Library of Input and Output */
#include <complex.h>    /* Standard Library of Complex Numbers */

int main() {

    double complex z1 = 1.0 + 3.0 * I;
    double complex z2 = 1.0 - 4.0 * I;

    printf("Working with complex numbers:\n\v");
    printf("real part of Z1 = %.2f \n", creal(z1));
    printf("real part of Z1 = %.2f \n", cimag(z1));

    printf("Starting values: Z1 = %.2f + %.2fi\tZ2 = %.2f %+.2fi\tZ3 = 1.0 +0.0i\tZ4 = 8.47 + 5.41i\n", creal(z1), cimag(z1), creal(z2), cimag(z2));

    double complex sum = z1 + z2;
    printf("The sum: Z1 + Z2 = %.2f %+.2fi\n", creal(sum), cimag(sum));

    double complex difference = z1 - z2;
    printf("The difference: Z1 - Z2 = %.2f %+.2fi\n", creal(difference), cimag(difference));

    double complex product = z1 * z2;
    printf("The product: Z1 x Z2 = %.2f %+.2fi\n", creal(product), cimag(product));

    double complex quotient = z1 / z2;
    printf("The quotient: Z1 / Z2 = %.2f %+.2fi\n", creal(quotient), cimag(quotient));

    double abs = cabs(z1);
    printf("The absolute value of Z1 = %.2f \n",abs);


    double complex conjugate = conj(z1);
    printf("The conjugate of Z1 = %.2f %+.2fi\n", creal(conjugate), cimag(conjugate));

    double complex sinP=csin(z1);
    printf("The sin of Z1 = %.2f %+.2fi\n", creal(sinP), cimag(sinP));

    double complex z3=1.0 + 0.0*I;
    double phase=carg(z3);
    printf("The phase of Z3 = %.2f\n",phase);

    double complex z4=8.47 +5.41*I;//sin of z1
    z3=casin(z4);
    printf("The sine inverse of Z4 = %.2f %+.2fi\n", creal(z3), cimag(z3));

    double complex power=cpow(z1,z2);
    printf("Z1 raised to power Z2 = %.2f %+.2fi\n", creal(power), cimag(power));
    double complex log=clog(z1);
    printf("The log of Z1 = %.2f %+.2fi\n", creal(log), cimag(log));
    double complex sqrt=csqrt(z1);
    printf("The sqrt of Z1 = %.2f %+.2fi\n", creal(sqrt), cimag(sqrt));
    double complex exp=cexp(z1);
    printf("The exp of Z1 = %.2f %+.2fi\n", creal(exp), cimag(exp));


    return 0;
}
