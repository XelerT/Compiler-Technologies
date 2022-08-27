/**
\file
\brief Header file with possible mistakes.
*/

#ifndef ERRORS_H
#define ERRORS_H

enum errors {
        WTF = -2,               ///<Heppend smth strange, you wanted to make \f$ n \f$ equal to \f$ 0 \f$ when \f$ n \f$ != \f$ 0 \f$
        BUFF_OVERFLOW = -3,     ///<Buffer's been overflowed
        ERROR = -4,             ///<Common error
};

#endif /* ERRORS_H */
