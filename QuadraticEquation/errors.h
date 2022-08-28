/**
\file
\brief Header file with possible mistakes.
*/
#ifndef ERRORS_H
#define ERRORS_H

/// Possible errors.
enum errors {
        MATH_ERROR = -2,               ///< Happend smth strange, you wanted to make \f$ n \f$ equal to \f$ 0 \f$ when \f$ n \f$ != \f$ 0 \f$
        BUFF_OVERFLOW = -3,            ///< Buffer's been overflowed
        INVLD_SYMB_ERROR = -4,         ///< Error caused by not a number symbles
};

#endif /* ERRORS_H */
