#include <stdio.h>
#include <math.h>


double coeff[3]; // a, b, c
                 // 0, 1, 2

void getCoefficient(int k) {

    printf("Enter argument %c:\n\t", 'a' + k);
    scanf("%lf", &coeff[k]);
    k++;

}

void giveAnswer(double a, double b, double c) {

    double D = b * b - 4 * a * c;

    printf("  Answer:\n");

    if (D > 0) {
        double x1 = (-b + sqrt(D))/(2 * a);
        double x2 = (-b - sqrt(D))/(2 * a);
        printf("\tD = %lf,\n\tx1 = %lf,\n\tx2 = %lf", D, x1, x2);
    } else if (D == 0) {
        double x = (-b)/(2 * a);
        printf("\tD = %lf,\n\tx1 = x2 = %lf", D, x);
    } else {
        printf("\tD = %lf,\n\tx1, x2 in complex field", D);
    }
}

int main() {

    for (int i = 0; i < 3; i++) {
        getCoefficient(i);
    }

    giveAnswer(coeff[0], coeff[1], coeff[2]);

    return 0;
}
