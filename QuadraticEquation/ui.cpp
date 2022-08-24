#include <stdio.h>
#include <assert.h>
#include "ui.h"
#include "errors.h"

void get_coefficients(polynomial_t *poly)
{
        for (int i = 0; i < poly->degree + 1; i++) {
                printf("Enter %d coefficient of equation:\n", i + 1);
                assert(scanf("%lf", &poly->coeffs[i]));
        }
}

int get_degree(void)
{
        int degree = 0;
        printf("Enter degree of your equation, please.\n");

        while (degree == 0) {
                assert(scanf("%d", &degree));
                if (degree > MAX_DEGREE) {
                        degree = 0;
                        printf("Sorry, we can't solve your equation(degree is too high).\n"
                        "Enter degree of your equation again.\n");
                } else if (degree <= 0) {
                        degree = 0;
                        printf("Sorry, we can't solve your equation(degree is too low).\n"
                        "Enter degree of your equation again.\n ");
                }
        }

        return degree;
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
        case WTF:
                printf("\tYou entered smth strange. Your last coefficient equals 0.");
        }

        for (int i = 0; i < n_roots; i++) {
                printf("\tx%d = %lf\n", i + 1, roots[i]);
        }
}
