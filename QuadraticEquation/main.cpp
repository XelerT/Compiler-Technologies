/**
        \brief Main file in project.
        Handles user commands:
        -help show all commands to user.
        -solve start solving polynom.
        -menu return to menu.
        -quit exit program.
*/

#include <stdio.h>
#include <assert.h>
#include "ui.h"

static unsigned int MAX_LINE = 10;
static const int MAX_DEGREE = 2;

int main()
{
        double coeffs[MAX_DEGREE + 1] = {0};
        double roots[MAX_DEGREE] = {0};

        int n_roots = 0;

        char buff[MAX_LINE] = {'\0'};

        cleare_screen();
        while (strncmp(buff, "quit", strlen("quit"))) {

                printf("\tMenu:\n"
                        "*******************\n");

                while (get_line(buff, MAX_LINE))
                        too_long(MAX_LINE - 1);

                if (!strncmp(buff, "solve", sizeof(buff))) {
                        int degree = 0;
                        while ((degree = get_degree(MAX_DEGREE, buff, MAX_LINE)) == ERROR)
                                enter_num();

                        while (get_coefficients(coeffs, buff, MAX_LINE, degree))
                                enter_num();

                        polynomial_t poly = {
                                .coeffs = coeffs,
                                .degree = degree
                        };

                        n_roots = solve_polynomial(roots, &poly);
                        give_answer(roots, n_roots);
                        zero_arr(buff, strlen(buff));
                } else if (!strncmp(buff, "menu", sizeof(buff))) {
                        cleare_screen();
                        zero_arr(buff, strlen("menu"));
                } else if (!strncmp(buff, "help", sizeof(buff))) {
                        cleare_screen();
                        printf(" Help:                            \n"
                               "\tsolve --> start solving polynom \n"
                               "\tmenu --> return to menu         \n"
                               "\tquit --> exit program.          \n\n");
                } else if (!strncmp(buff, "quit", sizeof(buff))) {
                        return 0;
                }  else {
                        printf("Sorry, I can't understand you.\n");
                }

                zero_arr(buff, MAX_LINE);
        }

        return 0;
}
