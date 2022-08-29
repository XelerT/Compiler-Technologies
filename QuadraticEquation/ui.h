/**
\file
\brief Main header file with user interface function.
*/

#ifndef UI_H
#define UI_H
#include <string.h>
#include "errors.h"
#include "compare.h"
#include "solution.h"

/**
Function get coefficients from user using function get_line from ui.cpp. Return 0 if all coefficients have been got
\param[out] coeffs - array of coefficients which we get in this function from user.
\param[in] buff is a buffer which used to store all input from user.
\param[in] lim if a limit for buffer.
\param[in] degree is a degree of polynomial which user want to solve.
*/
int get_coefficients(double coeffs[], char buff[], const int lim, long degree);

/**
Function get degree from user using function get_line from ui.cpp. Return degree which has been got.
\param[in] max_degree is maximum equation degree which program can solve at that moment.
\param[in] buff is a buffer which used to store all input from user.
\param[in] lim if a limit for buffer.
*/
long get_degree(const int max_degree, char buff[], const int lim);

/**
Function handles line from user, using buffer. Checks line on end of line(\n), EOF and free strorage in buffer.
After last symbol from user adds '\0' at the end of buffer. Returns 0, when all is ok.
\param[out] Buffer used to store line from user.
\param[in] Maximum symbols user can give to program through buffer.
*/
int get_line(char buff[], int lim);

/**
Function get degree from user using function get_line from ui.cpp. Give line from user to buffer.
\param[in] Roots which we got after solution.
\param[in] Number of roots in equation.
*/
void give_answer(double *roots, int n_roots);

void zero_arr (char buff[], size_t n);

/**
Funtion print message when buffer is overflowed.
\param[in] Maximum length of a line from user.
*/
void print_too_long(int lim);

/**
Funtion print message when user entered something other then numbers.
*/
void print_enter_num();

#endif /* UI_H */
