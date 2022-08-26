#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>

#include "ui.h"

int get_coefficients(double coeffs[], char buff[], const int lim, int degree)
{
        for (int i = 0; i < degree + 1; i++) {
                printf("Enter %d coefficient of equation:\n\t", i + 1);

                while (get_line(buff, lim))
                        too_long(lim - 1);

                char *end = NULL;
                double get_end = strtod(buff, &end);
                if (buff == end) {

                        return ERROR;

                } else {

                        coeffs[i] = strtod(buff, &end);
                }
                // case HUGE_VAL:
                //         return ERROR;
                }
                return 0;
}

int get_degree(const int max_degree, char buff[], const int lim)
{
        int degree = 0;
        printf("Enter degree of your equation, please.\n\t");

        while (degree == 0) {

                while (get_line(buff, lim))
                        too_long(lim);

                char *end = 0;
                degree = strtod(buff, &end);
                if (buff == end) {/// dsafasdf asdf asdf asd{
                        return ERROR;
                } else {
                        degree = strtod(buff, &end);
                }

                if (degree > max_degree) {
                        degree = 0;
                        printf("Sorry, we can't solve your equation(degree is too high).\n"
                        "Enter degree of your equation again.\n\t");
                } else if (degree <= 0) {
                        degree = 0;
                        printf("Sorry, we can't solve your equation(degree is too low).\n"
                        "Enter degree of your equation again.\n\t");
                }
        }

        return degree;
}

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
        }
}

int get_line(char *buff, const int lim)
{
        scanf("%s", buff); // cppref getchar
        int i = 0;
        while (buff[i] != '\0' && i <= lim - 1)
                i++;
        if (i >= lim - 1) {

                return BUFF_OVERFLOW;

        } else {
                buff[++i] = '\0';
        }

        return 0;
}

void zero_arr(char buff[], int n)
{
        for (int i = 0; i < n; i++) {
                buff[i] = '\0';
        }
}

void too_long(int lim)
{
        printf("Your line is too long(max is %d symbs). Try again.\n", lim - 1);
}

void enter_num()
{
        printf("You need to enter numbers. Try again.\n");
}
