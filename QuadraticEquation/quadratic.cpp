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


void get_coefficients(polynomial *poly)
{
        for (int i = 0; i < MAX_NUM_ROOTS + 1; i++) {
                printf("Enter %d coefficient of equation:\n", i + 1);
                scanf(" %lf", &poly->coeffs[i]);
        }
}

int solve_linear(double *roots, const polynomial *poly)
{
        const double *coeffs = poly->coeffs;
        if (coeffs[1] == 0 && coeffs[2] == 0) {
                return SS_INF_ROOTS;
        } else {
                roots[0] = -coeffs[0] / coeffs[1];
                return 1;
        }
}

int solve_quadratic(double *roots, const polynomial *poly)
{
        const double *coeffs = poly->coeffs;
        double discr = coeffs[1] * coeffs[1] - 4 * coeffs[0] * coeffs[2];
        if (coeffs[0] != 0) {
                if (fabs(discr) < epsilon) {
                        roots[0] = (-coeffs[1]) / (2 * coeffs[0]);
                        return 1;
                } else if (discr > 0) {
                        roots[0] = (-coeffs[1] + sqrt(discr)) / (2 * coeffs[0]);
                        roots[1] = (-coeffs[1] - sqrt(discr)) / (2 * coeffs[0]);
                        return 2;
                } else {
                        return 0;
                }
        } else {
                return solve_linear(roots, poly);
        }
}

void give_answer(double *roots, int n_roots)
{
        printf("  Answer:\n");
        switch (n_roots) {
        case 2:
                printf("\n\tx1 = %lf,\n\tx2 = %lf.\n", roots[0], roots[1]);
                break;
        case 1:
                printf("\tx1 = %lf.\n", roots[0]);
                break;
        case SS_INF_ROOTS:
                printf("\tThere infinite number of roots.\n");
                break;
        default:
                printf("\tThere are no roots.\n");
                break;
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
        polynomial poly = {};
        poly.coeffs = coeffs;
        poly.degree = degree;

        get_coefficients(&poly);
        n_roots = solve_quadratic(roots, &poly);
        give_answer(roots, n_roots);

        return 0;
}
