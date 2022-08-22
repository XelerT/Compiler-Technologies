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

void calculate_lin_ans(Equation *equ) {
    equ->x1 = -(equ->c) / (equ->b);
    equ->root_counter = 1;
}

void calculate_quadr_answer(Equation *equ) {
    double D = equ->b * equ->b - 4 * equ->a * equ->c;
    if (equ->a != 0) {
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
    } else {
        calculate_lin_ans(equ);
    }
}

void give_answer(Equation *equ) {

    printf("  Answer:\n");

    if (equ->root_counter == 2) {
        printf("\n\tx1 = %lf,\n\tx2 = %lf.\n", equ->x1, equ->x2);
    } else if (equ->root_counter == 1) {
        printf("\tx1 = %lf.\n", equ->x1);
    } else {
        printf("\tThere are no roots.\n");
    }

}


int main() {

    Equation equ = {};

    get_coefficient(&equ);
    calculate_quadr_answer(&equ);
    give_answer(&equ);

    return 0;
}
