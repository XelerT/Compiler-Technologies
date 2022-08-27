/**
        \brief Solves polynomials.
        \Now possible to solves linear and quadratic equations
*/

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "ui.h"

/**
Function solves linear equations. Returns number of roots through solve_polynomial.
\param[in] pointer which store roots of equation.
\param[out] poly - pointer on struture, used to deliver coefficients.
**/

int solve_linear(double *roots, const polynomial_t *poly)
{
        const double *coeffs = poly->coeffs;
        //assert(*coeffs);
        if (is_equal(coeffs[0], 0, THRESHOLD) && is_equal(coeffs[1], 0, THRESHOLD)) {
                return INF_ROOTS;
        } else if (is_equal(coeffs[0], 0, THRESHOLD) && !is_equal(coeffs[0], 0, THRESHOLD)) {
                return WTF; // rename?
        } else {
                //assert(coeffs[0]);
                roots[0] = -coeffs[1] / coeffs[0];
                return 1;
        }
}

/**
Function solves quadratic equations.
\f$ ax^2 + bx + c = 0 \f$
Discr - disriminant \f$ = b^2 - 4 * a * c \f$
root[0] - \f$ x_1\f$ if Discr(D) = 0:
                      \f$ x_1 = -b / 2 * c\f$
                     if Discr(D) > 0:
                      \f( x_1 = -b + scrt{D} / 2 * c\f)
root[1] - \f( x_2\f) if Discr(D) > 0:
                      \f$ x_1 = -b - sqrt{D} / 2 * c\f$
Returns number of roots through solve_polynomial.
\param[in] pointer which store roots of equation.
\param[in] poly - pointer on struture, used to deliver coefficients.
**/

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
        } else /*if (coeffs[2] == 0)*/ {
                const double linear_coeffs[2] = {coeffs[1], coeffs[2]};

                polynomial_t poly_linear = {}; //
                poly_linear.coeffs = linear_coeffs;
                poly_linear.degree = 1;

                return solve_linear(roots, &poly_linear);
        }
        //assert(*roots);
        printf("%lf\n", *roots);
}

/**
\ Function can be used to solve cubic equations in the future.
\param[in] pointer which store roots of equation.
\param[out] poly - pointer on struture, use to deliver coefficients.
**/
int solve_cubic (double *roots, const polynomial_t *poly) {
       assert(0);
       return WTF;
}

/**
It is manager who consider which equation to solve, based on user request. Returns n_roots.
\param[in] pointer which store roots of equation.
\param[in] poly - pointer on struture, used to deliver degree.
**/
int solve_polynomial (double *roots, const polynomial_t *poly)
{
        switch (poly->degree) {
        case 1:
                return solve_linear(roots, poly);
        case 2:
                return solve_quadratic(roots, poly);
        default:
                assert(0);
                return WTF;
        }
}
