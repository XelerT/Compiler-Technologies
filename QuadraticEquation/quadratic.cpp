#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "quadratic.h"
#include "quadratic.h"

/**
        Solves a square equation
        @param [in] a - coefficient
        @param [out] x1
**/

void get_coefficients(polynomial_t *poly)
{
        for (int i = 0; i < poly->degree + 1; i++) {
                printf("Enter %d coefficient of equation:\n", i + 1);
                assert(scanf("%lf", &poly->coeffs[i]));
        }
}

int solve_linear(double *roots, const polynomial_t *poly)
{
        const double *coeffs = poly->coeffs;
        if (coeffs[1] == 0) {
                return INF_ROOTS;
        } else {
                assert(coeffs[1]);
                roots[0] = -coeffs[1] / coeffs[0];
                return 1;
        }
}

int solve_quadratic(double *roots, const polynomial_t *poly)
{
        const double *coeffs = poly->coeffs;
        double discr = coeffs[1] * coeffs[1] - 4 * coeffs[0] * coeffs[2];
        if (coeffs[0] != 0) {
                if (is_equal(discr, 0, EPSILON)) {
                        roots[0] = (-coeffs[1]) / (2 * coeffs[0]);
                        return 1;
                } else if (is_greater(discr, 0, EPSILON)) {
                        roots[0] = (-coeffs[1] + sqrt(discr)) / (2 * coeffs[0]);
                        roots[1] = (-coeffs[1] - sqrt(discr)) / (2 * coeffs[0]);
                        return 2;
                } else {
                        return 0;
                }
        } else if (coeffs[2] == 0) {
                const double linear_coeffs[2] = {coeffs[0], coeffs[1]};

                polynomial_t poly_linear = {};
                poly_linear.coeffs = linear_coeffs;
                poly_linear.degree = 1;

                return solve_linear(roots, &poly_linear);
        }
}

int solve_cubic (double *roots, const polynomial_t *poly) {
       assert(0);
       return -2; //error
}

int solve_polynomial (double *roots, const polynomial_t *poly)
{
        switch (poly->degree) {
        case 1:
                return solve_linear(roots, poly);
        case 2:
                return solve_quadratic(roots, poly);
        default:
                assert(0);
                return -2; // error
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

int is_equal (double a, double b, const double threshold)       //a == b
{
        return fabs(a-b) < threshold;
}

int is_greater (double a, double b, const double threshold)       //a > b
{
        if (is_equal(a, b, threshold)) {
                return 0;
        } else if (a > b) {
                return 1;
        } else {
                return 0;
        }
}

int is_lower (double a, double b, const double threshold)       //a < b
{
        if (is_equal(a, b, threshold)) {
                return 0;
        } else if (a < b) {
                return 1;
        } else {
                return 0;
        }
}

int main()
{
        int degree = get_degree();

        double coeffs[2 + 1] = {0};    //need to replace
        double roots[2] = {0};         //need to replace

        int n_roots = 0;

        //polynomial poly = {
        //        .coeffs = coeffs,
        //        .degree = degree
        //};
        polynomial_t poly = {};
        poly.coeffs = coeffs;
        poly.degree = degree;

        get_coefficients(&poly);
        n_roots = solve_polynomial(roots, &poly);
        give_answer(roots, n_roots);

        return 0;
}
