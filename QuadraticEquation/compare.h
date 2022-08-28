/**
\file
\brief Header file with comparative functions prototypes.
*/
#ifndef COMPARE_H
#define COMPARE_H

static const double THRESHOLD = 1e-5;

/**
Compare two double constants with threshold. Returns true if first and second numbers are equal.
\param[in] First number.
\param[in] Second number.
\param[in] Threshold
*/
int is_equal   (double a, double b, const double threshold); // параметры по умолчанію

/**
Compare two double constants with threshold. Returns true if first is lower than second.
\param[in] First number.
\param[in] Second number.
\param[in] Threshold
*/
int is_lower   (double a, double b, const double threshold);

/**
Compare two double constants with threshold. Returns true if first is greater than second.
\param[in] First number.
\param[in] Second number.
\param[in] Threshold
*/
int is_greater (double a, double b, const double threshold);

#endif /* COMPARE_H */
