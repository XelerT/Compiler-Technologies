/**
\file
\brief Header for unitests.
*/

#ifndef UNITESTS_H
#define UNITESTS_H

static const int N_TESTS = 1;
static const int MAX_DEGREE = 2;

struct test_t {
        polynomial_t poly = {0};
        const double *roots  = nullptr;
};

/**
        Function checks right and calculated roots for quality.
        \param[in] pointer on struture, use to deliver coefficients and degree of polynom.
        \param[in] Roots of equation that have been calculated by the program.
        \param[in] Right roots of equation which must be calculated by the program.
        \param[in] Number of roots that has been calculated by the program.
        \param[in] Right number of roots is roots which must be calculated by the program.
        \param[in] Number of test.
*/
void check_test(const polynomial_t *poly, double *roots, const double *right_roots, int n_roots, int right_n_roots, int i);

/**
        Returns true if elements in that array are equal.
        \param[in] First array.
        \param[in] Second array.
        \param[in] Threshold.
*/
int compare_array(const double *arr1, double *arr2, const double threshold);

/**

        \param[in] First  coefficient of polynomial.
        \param[in] Second coefficient of polynomial.
        \param[in] Third  coefficient of polynomial.
        \param[in] First  right root of equation which must be calculated by the program.
        \param[in] Second right root of equation which must be calculated by the program.
*/
void run_test(double a, double b, double c, double d, double e, int right_n_roots, int i);

/**
        Print message that test has been passed.
*/
void print_passed();

#endif // UNITESTS_H
