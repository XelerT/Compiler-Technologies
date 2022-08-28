/**
        \brief Solves polynomials.
        \Now possible to solve linear and quadratic equations.
*/

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "ui.h"

int solve_linear(double *roots, const polynomial_t *poly)
{
        // ass
        const double *coeffs = poly->coeffs;
        //assert(*coeffs);
        if (is_equal(coeffs[0], 0, THRESHOLD) && is_equal(coeffs[1], 0, THRESHOLD)) {
                return INF_ROOTS;
        } else if (is_equal(coeffs[0], 0, THRESHOLD) && !is_equal(coeffs[0], 0, THRESHOLD)) { //
                return MATH_ERROR;
        } else {
                //assert(coeffs[0]);
                roots[0] = -coeffs[1] / coeffs[0];
                return 1;
        }
}

int solve_quadratic(double *roots, const polynomial_t *poly) //asse
{

        const double *coeffs = poly->coeffs;
        double discr = coeffs[1] * coeffs[1] - 4 * coeffs[0] * coeffs[2];
        //assert(*coeffs);
        if (!is_equal(coeffs[0], 0, THRESHOLD)) {   //coeffs[0] != 0
                if (!is_equal(coeffs[2], 0, THRESHOLD)) {
                        //assert(coeffs[0]);
                        if (is_equal(discr, 0, THRESHOLD)) {
                                roots[0] = (-coeffs[1]) / (2 * coeffs[0]);

                                return 1;
                        } else if (is_greater(discr, 0, THRESHOLD)) {
                                double sqt_discr = sqrt(discr);
                                roots[0] = (-coeffs[1] + sqt_discr) / (2 * coeffs[0]);
                                roots[1] = (-coeffs[1] - sqt_discr) / (2 * coeffs[0]);

                                return 2;
                        } else {
                                return 0;
                        }
                } else {
                        roots[0] = 0;
                        roots[1] = -coeffs[1] / coeffs[0];

                        return 2;
                }
        } else if (is_equal(coeffs[1], 0, THRESHOLD) && !is_equal(coeffs[2], 0, THRESHOLD)) {

                return MATH_ERROR;

        } else {
                const double linear_coeffs[2] = {coeffs[1], coeffs[2]};

                polynomial_t poly_linear = {}; //
                poly_linear.coeffs = linear_coeffs;
                poly_linear.degree = 1;

                return solve_linear(roots, &poly_linear);
        }
        //assert(*roots);
        // printf("%lf\n", *roots);
}

int solve_cubic (double *roots, const polynomial_t *poly) {
        assert(0);
        printf("We can't solve your cubic equation now.");
        const double *coeffs = poly->coeffs;
        roots[0] = 0;
        printf("%lf", coeffs[0]);

        return MATH_ERROR;
}

int solve_polynomial (double *roots, const polynomial_t *poly)
{
        switch (poly->degree) {
        case 1:
                return solve_linear(roots, poly);
        case 2:
                return solve_quadratic(roots, poly);
        // case 3:
        //         return solve_cubic(roots, poly);
        default:
                assert(0);
                return MATH_ERROR;
        }
}
