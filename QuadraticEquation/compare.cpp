/**
        \brief Functions using to compare double variables.
*/

#include <stdio.h>
#include <math.h>
#include "compare.h"

/**
Compare two double constants with threshold. Returns true if first and second numbers are equal.
\param[in] First number.
\param[in] Second number.
\param[in] Threshold
*/

int is_equal (const double a, const double b, const double threshold)       //a == b
{
        return fabs(a-b) < threshold;
}

/**
Compare two double constants with threshold. Returns true if first is greater than second.
\param[in] First number.
\param[in] Second number.
\param[in] Threshold
*/

int is_greater (const double a, const double b, const double threshold)       //a > b
{
        if (is_equal(a, b, threshold)) {
                return 0;
        } else {
                return a > b;
        }
}

/**
Compare two double constants with threshold. Returns true if first is lower than second.
\param[in] First number.
\param[in] Second number.
\param[in] Threshold
*/

int is_lower (const double a, const double b, const double threshold)       //a < b
{
        if (is_equal(a, b, threshold)) {
                return 0;
        } else {
                return a < b;
        }
}
