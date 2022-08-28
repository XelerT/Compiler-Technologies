/**
\file
\brief Header file polynomial_t struct, possible roots outside real numbers.
\todo Manager --> function pointer
*/
#ifndef SOLUTION_H
#define SOLUTION_H

enum nontrivial_roots {
        NO_ROOTS  =  0,     ///< No roots in equation.
        INF_ROOTS = -1,     ///< Infinity of roots in equation.
        };

struct polynomial_t
{
    const double *coeffs = nullptr;     ///< Contains coefficients of polynom.
    long degree = 0;                    ///< Contains degree of equation, entered by user.
};

/**
Function solves linear equations. Returns number of roots through solve_polynomial.
\param[in] pointer which store roots of equation.
\param[out] poly - pointer on struture, used to deliver coefficients.
**/
int solve_linear    (double *roots, const polynomial_t *poly);

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
int solve_quadratic (double *roots, const polynomial_t *poly);

/**
Function can be used to solve cubic equations in the future.
\param[in] pointer which store roots of equation.
\param[out] poly - pointer on struture, use to deliver coefficients.
**/
int solve_cubic     (double *roots, const polynomial_t *poly);

/**
It is manager who consider which equation to solve, based on user request. Returns n_roots.
\param[in] pointer which store roots of equation.
\param[in] poly - pointer on struture, used to deliver degree.
**/
int solve_polynomial (double *roots, const polynomial_t *poly);

#endif /* SOLUTION_H */
