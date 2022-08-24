#ifndef UI_H
#define UI_H

        enum nontrivial_roots {
                NO_ROOTS  =  0,
                INF_ROOTS = -1,
        };

        struct polynomial_t
        {
            const double *coeffs = nullptr;
            int degree = 0;
        };

        static const double MAX_DEGREE =  2;

        void get_coefficients(polynomial_t *poly);
        int get_degree(void);

        void give_answer(double *roots, int n_roots);

#endif /* UI_H */
