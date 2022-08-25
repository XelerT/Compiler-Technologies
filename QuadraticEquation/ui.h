#ifndef UI_H
#define UI_H
#include "common_structs.h"
#include "common_consts.h"

        enum nontrivial_roots {
                NO_ROOTS  =  0,
                INF_ROOTS = -1,
        };

        static const double MAX_DEGREE =  2;
        unsigned int MAX_LINE = 1000;

        void get_coefficients(polynomial_t *poly);
        int get_degree(void);
        void get_line(char buff[], int lim);

        int solve_polynomial(double *roots, const polynomial_t *poly);

        void give_answer(double *roots, int n_roots);

        void zero_arr (char buff[]);
        int same_str(char buff[], char line[]);

#endif /* UI_H */
