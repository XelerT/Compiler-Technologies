#include <stdio.h>
#include <math.h>

enum  {
     NO_ROOTS =  0,
    INF_ROOTS = -1,
    POSSIBLE_EQU_DEGREE = 2, //N_MAX_DEGREE

};

struct polynomial
{
        const double *coeffs = nullptr;
        int degree = 0;
};

static const double epsilon = 1e-15;


void get_coefficients(polynomial *poly)
{
        for (int i = 0; i < poly->degree + 1; i++) {
                printf("Enter %d coefficient of equation:\n", i + 1);
                scanf(" %lf", &poly->coeffs[i]);
        }
}

int solve_linear(double *roots, const polynomial *poly)
{
        const double *coeffs = poly->coeffs;
        if (coeffs[1] == 0 && coeffs[2] == 0) {
                return INF_ROOTS;
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

        case INF_ROOTS:
                printf("\tThere infinite number of roots.\n");
                break;
        case NO_ROOTS:
                printf("\tThere are no roots.\n");
                break;
        }

        for (int i = 0; i < n_roots; i++) {
                printf("\tx%d = %lf\n", i + 1, roots[i]);
        }
}

int get_degree(void) {
        int degree = 0;
        printf("Enter degree of your equation, please.\n");
        while (degree == 0) {
                scanf("%d", &degree);
                if (degree > POSSIBLE_EQU_DEGREE) {
                        degree = 0;
                        printf("Sorry, we can't solve your equation(degree is too high).\n Enter degree of your equation again.\n");
                } else if (degree <= 0) {
                        degree = 0;
                        printf("Sorry, we can't solve your equation(degree is too low).\n Enter degree of your equation again.\n ");
                }
        }
        return degree;
}

//int solve_cubic (double *roots, const polynomial *poly) {
//        const double *coeffs = polly->coeffs;
//}


int main()
{
        int degree = get_degree();
//        if (degree == 1) {
//                double coeffs[2] = {0};
//                double roots[1] = {0};
//        } else if (degree == 2) {
//                double coeffs[3] = {0};
//                double roots[2] = {0};
//        }

        double coeffs[2 + 1] = {0};
        double roots[2] = {0};

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
