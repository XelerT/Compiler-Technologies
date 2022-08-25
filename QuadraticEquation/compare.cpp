#include <stdio.h>
#include <math.h>
#include "compare.h"

int is_equal (const double a, const double b, const double threshold)       //a == b
{
        return fabs(a-b) < threshold;
}

int is_greater (const double a, const double b, const double threshold)       //a > b
{
        if (is_equal(a, b, threshold)) {
                return 0;
        } else if (a > b) { // ???
                return 1;
        } else {
                return 0;
        }
}

int is_lower (const double a, const double b, const double threshold)       //a < b
{
        if (is_equal(a, b, threshold)) {
                return 0;
        } else if (a < b) { //
                return 1;
        } else {
                return 0;
        }
}
