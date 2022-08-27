/**
        \brief Funtions which handle with commands from user.
*/
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>

static unsigned int MAX_LINE = 10;
#include "ui.h"

/**
Function get coefficients from user using function get_line from ui.cpp. Return 0 if all coefficients have been got
\param[out] coeffs - array of coefficients which we get in this function from user.
\param[in] buff is a buffer which used to store all input from user.
\param[in] lim if a limit for buffer.
\param[in] degree is a degree of polynomial which user want to solve.
*/
int get_coefficients(double coeffs[], char buff[], const int lim, int degree)
{
        for (int i = 0; i < degree + 1; i++) {
                printf(" Enter %d coefficient of equation:\n\t", i + 1);

                while (get_line(buff, lim))
                        too_long(lim - 1);

                char *end = NULL;
                coeffs[i] = strtod(buff, &end);
                if (buff == end || *(end + 1) != NULL)
                        return ERROR;
                zero_arr(buff, MAX_LINE);
        }

        return 0;
}

/**
Function get degree from user using function get_line from ui.cpp. Return degree which has been got.
\param[in] max_degree is maximum equation degree which program can solve at that moment.
\param[in] buff is a buffer which used to store all input from user.
\param[in] lim if a limit for buffer.
*/

int get_degree(const int max_degree, char buff[], const int lim)
{
        int degree = 0;
        printf(" Enter degree of your equation, please.\n\t");

        while (degree == 0) {

                while (get_line(buff, lim))
                        too_long(lim);

                char *end = NULL;
                degree = strtod(buff, &end);

                if (buff == end || *(end + 1) != 0)
                        return ERROR;

                if (degree > max_degree) {
                        degree = 0;
                        printf(" Sorry, we can't solve your equation(degree is too high).\n"
                        " Enter degree of your equation again.\n\t");
                } else if (degree <= 0) {
                        degree = 0;
                        printf(" Sorry, we can't solve your equation(degree is too low).\n"
                        " Enter degree of your equation again.\n\t");
                }
        }

        return degree;
}

/**
Function get degree from user using function get_line from ui.cpp. Give line from user to buffer.
\param[in] Roots which we got after solution.
\param[in] Number of roots in equation.
*/

void give_answer(double *roots, int n_roots)
{
        printf("  Answer:\n");

        switch (n_roots) {
        case INF_ROOTS:
                printf("\tThere infinite number of roots.\n");
                break;
        case NO_ROOTS:
                printf("\tThere are no roots.\n");
                break;
        case WTF:
                printf("\tYou entered smth strange. Your last coefficient equals 0.");
                break;
        default:
                for (int i = 0; i < n_roots; i++) {
                        printf("\tx%d = %lf\n", i + 1, roots[i]);
                }
                printf("\n");
        }
}

/**
Function handles line from user, using buffer. Checks line on end of line(\n), EOF and free strorage in buffer.
After last symbol from user adds '\0' at the end of buffer. Returns 0, when all is ok.
\param[out] Buffer used to store line from user.
\param[in] Maximum symbols user can give to program through buffer.
*/


int get_line(char *buff, const int lim)
{
        int s = 0;
        int i = 0;

        while ((s = getchar()) != '\n' && s != EOF) {
                buff[i] = (char) s;
                i++;
                if (i >= lim - 1)
                        return BUFF_OVERFLOW;
        }

        buff[i + 1] = '\0';

        return 0;
}

void zero_arr(char buff[], int n)
{
        for (int i = 0; i < n; i++) {
                buff[i] = '\0';
        }
}

/**
Funtion print message when buffer is overflowed.
\param[in] Maximum length of a line from user.
*/

void too_long(int lim)
{
        printf("Your line is too long(max is %d symbs). Try again.\n", lim - 1);
}

/**
Funtion print message when user entered something other then numbers.
*/
void enter_num()
{
        printf("You need to enter numbers. Try again.\n");
}

/**
Function clear command line screen.
*/

void cleare_screen()
{
        for (int i = 0; i < 50; i++) {
                printf("\n");
        }
}
