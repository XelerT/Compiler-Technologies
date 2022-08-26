/**
        \brief Run tests to check quadratic solver algorithm.
**/

#include <stdio.h>
#include <assert.h>
#include "ui.h"

static const int N_TESTS = 1;
static const int MAX_DEGREE = 2;

struct test_t {

        polynomial_t poly = {0};
        const double *roots  = nullptr;
};

void check_test(const test_t *test, double *roots, const double right_roots[], int n_roots, int right_n_roots);
int compare_array(const double *arr1, double *arr2, const double threshold);
void run_test(double a, double b, double c, double d, double e, int right_n_roots);
void pr_true();

void check_test(const test_t *test, double *roots, const double *right_roots, int n_roots, int right_n_roots)
{
        if (n_roots == INF_ROOTS) {
                pr_true();
        } else if (n_roots == WTF) {
                pr_true();
        } else if (n_roots == NO_ROOTS) {
                pr_true();
        } else {
                if (compare_array(right_roots, roots, THRESHOLD)) {
                        pr_true();
                } else {
                        printf("Test %d:\t***FALSE***.\n");
                }
        }
}

void pr_true()
{
        printf("Test:\t TRUE.\n");
}

int compare_array(const double *arr1, double *arr2, const double threshold)
{
        for (int i = 0; i < MAX_DEGREE; i++) {
                if (!is_equal(arr1[i], arr2[i], threshold))
                        return 0;
        }
        return true;
}

void run_test(double a, double b, double c, double d, double e, int right_n_roots) {

        double roots[MAX_DEGREE] = {0};
        double coeffs[MAX_DEGREE] = {0};
        double right_roots[MAX_DEGREE] = {0};
        int n_roots = 0;

        coeffs[0] = a;
        coeffs[1] = b;
        coeffs[2] = c;

        right_roots[0] = d;
        right_roots[1] = e;

        test_t test = {0};

        test = {

                {
                         coeffs,
                         2
                 },
                 right_roots,

        };

                n_roots = solve_polynomial(roots, &(test.poly));
                check_test(&test, roots, test.roots, n_roots, right_n_roots);
}

int main()
{
        run_test(2, -8.5, 8, 2.84307, 1.40692, 2);
        run_test(2, -8, 8, 2, 0, 1);
        run_test(5, -25, 8, 4.65638, 0.34361, 2);
        run_test(134, 123, 5, -0.04263, -0.87528, 2);
        run_test(0, 0, 0, 0, 0, INF_ROOTS);
        run_test(1, 1, 1, 0, 0, NO_ROOTS);
        run_test(0, 0, 1, 0, 0, WTF);

        return 0;
}
