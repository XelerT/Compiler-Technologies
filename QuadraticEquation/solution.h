/**
\file
\brief Header file polynomial_t struct, possible roots outside real numbers.
\todo Manager --> function pointer
*/

#ifndef SOLUTION_H
#define SOLUTION_H

enum nontrivial_roots {
        NO_ROOTS  =  0,
        INF_ROOTS = -1,
        };

struct polynomial_t
{
    const double *coeffs = nullptr;
    int degree = 0;
};

int solve_linear    (double *roots, const polynomial_t *poly);
int solve_quadratic (double *roots, const polynomial_t *poly);
int solve_cubic     (double *roots, const polynomial_t *poly);

#endif /* SOLUTION_H */
