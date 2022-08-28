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

void check_test(const polynomial_t *poly, double *roots, const double *right_roots, int n_roots, int right_n_roots, int i);
int compare_array(const double *arr1, double *arr2, const double threshold);
void run_test(double a, double b, double c, double d, double e, int right_n_roots, int i);
void pr_true();

#endif // UNITESTS_H
