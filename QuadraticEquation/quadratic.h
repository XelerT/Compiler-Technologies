#ifndef QUADRATIC_H
#define QUADRATIC_H

    enum nontrivial_roots {
            NO_ROOTS  =  0,
            INF_ROOTS = -1,
    };

    struct polynomial_t
    {
            const double *coeffs = nullptr;
            int degree = 0;
    };

    static const double EPSILON = 1e-15;
    static const double MAX_DEGREE =  2;

    void get_coefficients(polynomial_t *poly);
    int get_degree(void);

    int solve_linear    (double *roots, const polynomial_t *poly);
    int solve_quadratic (double *roots, const polynomial_t *poly);
    int solve_cubic     (double *roots, const polynomial_t *poly);
    int solve_polynomial(double *roots, const polynomial_t *poly);

    void give_answer(double *roots, int n_roots);

    int is_equal   (double a, double b, const double threshold);
    int is_lower   (double a, double b, const double threshold);
    int is_greater (double a, double b, const double threshold);

#endif /* QUADRATIC_H */
