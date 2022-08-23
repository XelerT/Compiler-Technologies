#include <stdio.h>
#include <math.h>

static const int MAX_NUM_ROOTS = 2;
static const int SS_INF_ROOTS = -1;

struct polynomial
{
        const double *coeffs = nullptr;
        int degree = 0;
};

static const double epsilon = 1e-15;


void get_coefficients(polynomial *pol)
{
        for (int i = 0; i < MAX_NUM_ROOTS + 1; i++) {
                printf("Enter %d coefficient of equation:\n", i + 1);
                scanf(" %lf", &pol->coeffs[i]);
        }
}

int calculate_lin_ans(double *roots, const polynomial *pol)
{
        if (pol->coeffs[1] == 0 && pol->coeffs[2] == 0) {
                return SS_INF_ROOTS;
        } else {
                roots[0] = -(pol->coeffs[0]) / (pol->coeffs[1]);
                return 1;
        }
}

int calculate_quadr_answer(double *roots, const polynomial *pol)
{
        double Discr = pol->coeffs[1] * pol->coeffs[1] - 4 * pol->coeffs[0] * pol->coeffs[2];
        if (pol->coeffs[0] != 0) {
                if (fabs(Discr) < epsilon) {
                        roots[0] = (-pol->coeffs[1]) / (2 * pol->coeffs[0]);
                        return 1;
                } else if (Discr > 0) {
                        roots[0] = (-pol->coeffs[1] + sqrt(Discr)) / (2 * pol->coeffs[0]);
                        roots[1] = (-pol->coeffs[1] - sqrt(Discr)) / (2 * pol->coeffs[0]);
                        return 2;
                } else {
                        return 0;
                }
        } else {
                return calculate_lin_ans(roots, pol);
        }
}

void give_answer(double *roots, int n_roots)
{
        printf("  Answer:\n");
        switch (n_roots) {
                case 2: printf("\n\tx1 = %lf,\n\tx2 = %lf.\n", roots[0], roots[1]);
                        break;
                case 1: printf("\tx1 = %lf.\n", roots[0]);
                        break;
                case SS_INF_ROOTS:  printf("\tThere infinite number of roots.\n");
                                    break;
                default: printf("\tThere are no roots.\n");
        }
}


int main()
{
        double coeffs[MAX_NUM_ROOTS + 1] = {0};
        double roots[MAX_NUM_ROOTS] = {0};
        int degree = 0;
        int n_roots = 0;

//        polynomial pol = {
//                .coeffs = coeffs,
//                .degree = degree
//        };
        polynomial pol = {};
        pol.coeffs = coeffs;
        pol.degree = degree;

        get_coefficients(&pol);
        n_roots = calculate_quadr_answer(roots, &pol);
        give_answer(roots, n_roots);

        return 0;
}
