/**
        \brief Run tests to check quadratic solver algorithm.
*/

#include <stdio.h>
#include <assert.h>
#include "ui.h"
#include "unitests.h"

int main()
{
        int i = 0;

        run_test(2, -8.5, 8, 2.84307, 1.40692, 2, i++);
        run_test(2, -8, 8, 2, 0, 1, i++);
        run_test(5, -25, 8, 4.65638, 0.34361, 2, i++); // TWO_ROOTS
        run_test(134, 123, 6, -0.04263, -0.87528, 2, i++); //false 6 must be 5
        run_test(0, 0, 0, 0, 0, INF_ROOTS, i++);
        run_test(1, 1, 1, 0, 0, NO_ROOTS, i++);
        run_test(0, 0, 1, 0, 0, MATH_ERROR, i++);
        run_test(1, 5, 6, -2, -3, 2, i++);

        return 0;
}

void check_test(const polynomial_t *poly, double *roots, const double *right_roots, int n_roots, int right_n_roots, int i)
{
        assert(poly);

        const double *coeffs = poly->coeffs;

        if (n_roots == INF_ROOTS) {
                pr_true();
        } else if (n_roots == MATH_ERROR) {
                pr_true();
        } else if (n_roots == NO_ROOTS) {
                pr_true();
        } else {
                if (compare_array(right_roots, roots, THRESHOLD)) {
                        pr_true();
                } else {
                        printf("Test %d:\t***FALSE***.\n", i);
                        printf("\tExpected roots: %lf %lf\n", right_roots[0], right_roots[1]);
                        printf("\tExpected degree: %d ", right_n_roots);
                        if (right_n_roots == MATH_ERROR)
                                printf("Mathematical error.\n");
                        else if (right_n_roots == INF_ROOTS)
                                printf("Infinite number error.\n");
                        else if (right_n_roots == NO_ROOTS)
                                printf("No roots.\n");
                        printf("\tGiven coefficients: %lf, %lf, %lf", coeffs[0], coeffs[1], coeffs[2]);
                        printf("\tCalculated roots: %lf %lf\n", roots[0], roots[1]);
                        printf("\tCalculated degree: %d\n", n_roots);
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

void run_test(double a, double b, double c, double d, double e, int right_n_roots, int i) {

        double roots[MAX_DEGREE] = {0};
        double coeffs[MAX_DEGREE + 1] = {0};
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
        check_test(&(test.poly), roots, test.roots, n_roots, right_n_roots, i);
}
