/*!
\file
\brief Main header file with user interface function.
*/

#ifndef UI_H
#define UI_H
#include "errors.h"
#include "compare.h"
#include "solution.h"
#include "polynom.h"

int get_coefficients(double coeffs[], char buff[], const int lim, int degree);
int get_degree(const int max_degree, char buff[], const int lim);
int get_line(char buff[], int lim);

int solve_polynomial(double *roots, const polynomial_t *poly);

void give_answer(double *roots, int n_roots);

void zero_arr (char buff[], int n);
void too_long(int lim);
void enter_num();
void cleare_screen();

#endif /* UI_H */
