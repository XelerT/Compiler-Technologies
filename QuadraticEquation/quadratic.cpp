#include <stdio.h>
#include "polynom.h"

/**
        Solves a square equation
        @param [in] a - coefficient
        @param [out] x1
**/

int main()
{
        int degree = get_degree();

        double coeffs[2 + 1] = {0};    //need to replace
        double roots[2] = {0};         //need to replace

        int n_roots = 0;



        // g++ 8+
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
