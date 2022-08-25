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

// int same_str(char buff[], char line[])
// {
//         int same = 1;
//         for (int i = 0; i < MAX_LINE && buff[i] != '\0' && same; i++) {
//                 if (buff[i] != line[i]) {
//                         same = 0;
//                 }
//         }
//         return same;
// }
