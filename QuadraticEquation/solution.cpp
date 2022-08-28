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
        assert(roots);
        assert(poly);

        const double *coeffs = poly->coeffs;

        if (is_equal(coeffs[0], 0, THRESHOLD) && is_equal(coeffs[1], 0, THRESHOLD)) {
                return INF_ROOTS;
        } else if (is_equal(coeffs[0], 0, THRESHOLD) && !is_equal(coeffs[1], 0, THRESHOLD)) { //
                return MATH_ERROR;
        } else {
                roots[0] = -coeffs[1] / coeffs[0];
                return 1;
        }
}

int solve_quadratic(double *roots, const polynomial_t *poly)
{
        assert(roots);
        assert(poly);

        const double *coeffs = poly->coeffs;
        double discr = coeffs[1] * coeffs[1] - 4 * coeffs[0] * coeffs[2];

        if (!is_equal(coeffs[0], 0, THRESHOLD)) {
                if (!is_equal(coeffs[2], 0, THRESHOLD)) {
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

                polynomial_t poly_linear = {0};
                poly_linear.coeffs = linear_coeffs;
                poly_linear.degree = 1;

                return solve_linear(roots, &poly_linear);
        }
}

int solve_cubic (double *roots, const polynomial_t *poly)
{
        assert(roots);
        assert(poly);

        printf("We can't solve your cubic equation now.\n ");
        roots[0] = 0;

        return 3;
}

int solve_polynomial (double *roots, const polynomial_t *poly)
{
        assert(roots);
        assert(poly);

        switch (poly->degree) {
        case 1:
                return solve_linear(roots, poly);
        case 2:
                return solve_quadratic(roots, poly);
        case 3:
                return solve_cubic(roots, poly);
        default:
                assert(0);
                return MATH_ERROR;
        }
}
