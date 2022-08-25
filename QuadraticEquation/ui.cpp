#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "ui.h"
#include "errors.h"
#include "common_structs.h"

void get_coefficients(polynomial_t *poly)
{
        for (int i = 0; i < poly->degree + 1; i++) {
                printf("Enter %d coefficient of equation:\n", i + 1);
                assert(scanf("%lf", &poly->coeffs[i]));
        }
}

int get_degree(void)
{
        int degree = 0;
        printf("Enter degree of your equation, please.\n");

        while (degree == 0) {
                assert(scanf("%d", &degree));
                if (degree > MAX_DEGREE) {
                        degree = 0;
                        printf("Sorry, we can't solve your equation(degree is too high).\n"
                        "Enter degree of your equation again.\n");
                } else if (degree <= 0) {
                        degree = 0;
                        printf("Sorry, we can't solve your equation(degree is too low).\n"
                        "Enter degree of your equation again.\n ");
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
        default:
                for (int i = 0; i < n_roots; i++) {
                printf("\tx%d = %lf\n", i + 1, roots[i]);
                }
                break;
        }
}

int interface (double *roots, double *coeffs, int n_roots)
{
        char buff[MAX_LINE] = {'\0'};
        char command[MAX_LINE] = {'\0'};

        while (buff != "quit") {
                printf("Menu:\n\tsolve --> start solving polynom\n\tmenu --> return to menu\n\tquit --> exit program.\n");

                get_line(buff, MAX_LINE);
                assert(buff[0]);
                sscanf(buff, "%s %*s", command);
                //same_str(buff, "solve")
                if (same_str(buff, "solve")) {
                        int degree = get_degree();

                                polynomial_t poly = {
                                        .coeffs = coeffs,
                                        .degree = degree
                                };

                        get_coefficients(&poly);
                        n_roots = solve_polynomial(roots, &poly);
                        give_answer(roots, n_roots);
                        zero_arr(buff);
                } else if (same_str(buff, "menu")) {
                        zero_arr(buff);
                } else if (same_str(buff, "quit")) {
                        return 0;
                } else {
                        zero_arr(buff);
                        printf("Sorry, I can't understand you");
                }
        }
        return -1;
}

void get_line(char buff[], int lim)
{
        scanf("%s", buff);
        int i;

        for (i = 0; buff[i] != '\0'; i++) {
                lim++;
        }

        if (i == lim - 1) {
                char ans = 0;
                printf("Your line is too long\nDo you want to continue with it?[y/n]");
                if (scanf("%d", &ans) == 'y') {
                        zero_arr(buff);
                        get_line(buff, MAX_LINE);
                } else if (scanf("%d", &ans) == 'n') {
                      zero_arr(buff);
                }
        } else {
                buff[++i] = '\0';
        }
}

void zero_arr (char buff[])
{
        for (int i = 0; i < MAX_LINE; i++) {
                buff[i] = '\0';
        }
}

int same_str(char buff[], char line[])
{
        int same = 1;
        for (int i = 0; i < MAX_LINE && buff[i] != '\0' && same; i++) {
                if (buff[i] != line[i]) {
                        same = 0;
                }
        }
        return same;
}
