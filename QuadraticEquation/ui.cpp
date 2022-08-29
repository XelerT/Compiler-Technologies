/**
        \brief Funtions which handle with commands from user.
*/
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

static const unsigned MAX_LINE = 10;
#include "ui.h"

int get_coefficients(double coeffs[], char buff[], const int lim, long degree)
{
        assert(buff);

        for (int i = 0; i < degree + 1; i++) {
                printf(" Enter %d coefficient of equation:\n\t", i + 1);

                while (get_line(buff, lim))
                        print_too_long(lim);

                char *end = NULL;
                coeffs[i] = strtod(buff, &end);
                if (buff == end || *(end + 1) != NULL)
                        return INVLD_SYMB_ERROR;
                zero_arr(buff, MAX_LINE);
        }

        return 0;
}

long get_degree(const int max_degree, char buff[], const int lim)
{
        assert(buff);

        long degree = 0;
        printf(" Enter degree of your equation, please.\n\t");

        while (degree == 0) {

                while (get_line(buff, lim))
                        print_too_long(lim);

                char *end = NULL;
                degree = strtol(buff, &end, 10);

                if (buff == end || *(end + 1) != 0) {
                        zero_arr(buff, MAX_LINE - 1);
                        return INVLD_SYMB_ERROR;
                }

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

void give_answer(double *roots, int n_roots)
{
        assert(roots);

        printf("  Answer:\n");

        switch (n_roots) {
        case INF_ROOTS:
                printf("\tThere are infinite number of roots.\n ");
                break;
        case NO_ROOTS:
                printf("\tThere are no roots.\n ");
                break;
        case MATH_ERROR:
                printf("\tThere are no roots.\n ");
                break;
        default:
                for (int i = 0; i < n_roots; i++) {
                        printf("\tx%d = %lf\n", i + 1, roots[i]);
                }
                printf("\n");
        }
}

int get_line(char *buff, const int lim)
{
        assert(buff);

        int s1 = 0;
        int s2 = 0;
        int i = 0;

        do {
                buff[i] = (char) getchar();
        } while (isspace(buff[i]));

        s2 = buff[i];
        i++;
        while ((s1 = getchar()) != '\n' && s1 != EOF && (!isspace(s1) || !isspace(s2))) {
                s2 = s1;
                buff[i++] = (char) s1;
                if (i >= lim - 1) {
                        while ((s1 = getchar()) != '\n' && s1 != EOF)
                                ;
                        zero_arr(buff, MAX_LINE);

                        return BUFF_OVERFLOW;
                }
        }
        if (isspace(buff[i]))
                buff[i]     = '\0';
        else
                buff[i + 1] = '\0';

        return 0;
}

void zero_arr(char buff[], size_t n)
{
        assert(buff);

        for (size_t i = 0; i < n; i++) {
                buff[i] = '\0';
        }
}

void print_too_long(int lim)
{
        printf("\n Your line is too long (max is %d symbs). Try again.\n ", lim - 1);
}

void print_enter_num()
{
        printf("\n You need to enter numbers. Try again.\n ");
}
