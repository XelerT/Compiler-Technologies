#include <stdio.h>
#include "polynom.h"

/**
        Solves a square equation
        @param [in] a - coefficient
        @param [out] x1
**/

int main()
{

        double coeffs[2 + 1] = {0};    //need to replace
        double roots[2] = {0};         //need to replace

        int n_roots = 0;

        // polynomial_t poly = {
        //        .coeffs = coeffs,
        //        .degree = degree
        // };

        // get_coefficients(&poly);
        // n_roots = solve_polynomial(roots, &poly);
        // give_answer(roots, n_roots);

        return interface(roots, coeffs, n_roots);
}
