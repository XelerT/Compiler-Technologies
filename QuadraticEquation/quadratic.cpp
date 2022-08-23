#include <stdio.h>
#include <math.h>

static const MAX_NUM_ROOTS = 2;
static const SS_INF_ROOTS = -1;

struct polynomial
{
        const double *coeffs = nullptr;
        int degree = 0;
};


static const double epsilon = 1e-15;


void get_coefficients(Polynomial *pol)
{
        for (int i = 0; i < MAX_NUM_ROOTS + 1; i++) {
                printf("Enter %d coefficient of equation:\n", i);
                scanf("%lf\n", pol->coeffs[i]);
        }
//        int arr[2] = {0};
//        const int *ptr = arr;
//        int *const arr
//        arr++;
}

void calculate_lin_ans(double roots[], Polynomial *pol)
{
        if (b == 0 && c == 0) {
                pol->degree = SS_INF_ROOTS;
        } else {
                roots[0] = -(pol->coeffs[0]) / (pol->coeffs[1]);
                pol->degree = 1;
        }
}

void calculate_quadr_answer(double roots[], Polynomial *pol)
{
        double *coeffs = pol->coeffs;
        double D = b * b - 4 * a * c;
        if (a != 0) {
                if (fabs(D) < epsilon) {
                        roots[0] = (-coeffs[1]) / (2 * coeffs[0]);
                        pol->degree = 1;
                } else if (D > 0) {
                        roots[0] = (-coeffs[1] + sqrt(D)) / (2 * coeffs[0]);
                        roots[1] = (-b - sqrt(D)) / (2 * coeffs[0]);
                        pol->degree = 2;
                } else {
                        pol->degree = 0;
                }
        } else {
                calculate_lin_ans(roots, pol);
        }
}

void give_answer(double roots[])
{
        printf("  Answer:\n");
        switch (degree) {
                case 2: printf("\n\tx1 = %lf,\n\tx2 = %lf.\n", roots[0], roots[1]);
                        break;
                case 1:
                        printf("\tThere infinite number of roots.\n");
                        break;
                default: printf("\tThere are no roots.\n");
        }
}


int main()
{
        double coeffs[MAX_NUM_ROOTS + 1] = {0};
        double roots[MAX_NUM_ROOTS] = {0};

        Polynomial pol = {
                .coeffs = coeffs,
                .degree = degree
        };

        get_coefficient();
        calculate_quadr_answer();
        give_answer();

        return 0;
}
