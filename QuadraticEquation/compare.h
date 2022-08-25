#ifndef COMPARE_H
#define COMPARE_H

static const double THRESHOLD = 1e-15;

int is_equal   (double a, double b, const double threshold); // параметры по умолчанію
int is_lower   (double a, double b, const double threshold);
int is_greater (double a, double b, const double threshold);

#endif /* COMPARE_H */
