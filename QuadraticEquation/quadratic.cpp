#include <stdio.h>
#include <math.h>


struct Equation {

    double a = NAN;
    double b = NAN;
    double c = NAN;
    double x1 = NAN;
    double x2 = NAN;
    int root_counter = 0;

};

static const double epsilon = 1e-15;

void get_coefficient(Equation *equ) {

    printf("Enter 3 coefficients of quadratic equation:\n");
    scanf("%lf %lf %lf", &equ->a, &equ->b, &equ->c);
}

void culculate_answer(Equation *equ) {
    double D = equ->b * equ->b - 4 * equ->a * equ->c;
    if (fabs(D) < epsilon) {
        equ->x1 = (-equ->b)/(2 * equ->a);
        equ->root_counter = 1;
    } else if (D > 0) {
        equ->x1 = (-equ->b + sqrt(D))/(2 * equ->a);
        equ->x2 = (-equ->b - sqrt(D))/(2 * equ->a);
        equ->root_counter = 2;
    } else {
        equ->root_counter = 0;
    }
}

void give_answer(Equation *equ) {

    printf("  Answer:\n");

    if (equ->root_counter == 2) {
        printf("\n\tx1 = %lf,\n\tx2 = %lf.\n", equ->x1, equ->x2);
    } else if (equ->root_counter == 1) {
        printf("\tx1 = %lf.\n", equ->x1);
    } else {
        printf("\tx1, x2 in complex field.\n");
    }

}


int main() {

    Equation equ = {};

    get_coefficient(&equ);
    culculate_answer(&equ);
    give_answer(&equ);

    return 0;
}
