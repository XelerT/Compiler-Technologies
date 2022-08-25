#ifndef SOLUTION_H
#define SOLUTION_H
#include "common_structs.h"

        enum nontrivial_roots {
                NO_ROOTS  =  0,
                INF_ROOTS = -1,
        };

        static const double MAX_DEGREE =  2;

        int solve_linear    (double *roots, const polynomial_t *poly);
        int solve_quadratic (double *roots, const polynomial_t *poly);
        int solve_cubic     (double *roots, const polynomial_t *poly);

        // TODO: Manager --> function pointer
        int solve_polynomial(double *roots, const polynomial_t *poly);

#endif /* SOLUTION_H */
