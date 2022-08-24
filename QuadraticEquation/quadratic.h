#ifndef QUADRATIC_H
#define QUADRATIC_H

        struct polynomial_t
        {
            const double *coeffs = nullptr;
            int degree = 0;
        };

        int get_degree(void);
        void get_coefficients(polynomial_t *poly);

        int solve_polynomial(double *roots, const polynomial_t *poly);

        void give_answer(double *roots, int n_roots);

#endif /* QUADRATIC_H */
