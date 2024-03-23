#if !defined(____HEADER_GUARD_int_isOdd_h)
#define ____HEADER_GUARD_int_isOdd_h



#include "bool_type.h"
#include "int_type.h"



#define ____FUNCTION_DECLARATION_int_isOdd_TEMPLATE(signLetter_, size_) \
__attribute__ ((__always_inline__)) inline \
bool \
signLetter_ ## i ## size_ ## _isOdd\
(\
signLetter_ ## i ## size_ ## _t int__\
)



#define ____FUNCTION_BODY_int_isOdd_TEMPLATE(signLetter_, size_) \
{\
\
\
\
return (int__ % 2);/*((int__ % 2) == 1)*//* (int__ & 1) may be faster but may cause issues in some architectures ???*/\
\
\
\
}



____FUNCTION_DECLARATION_int_isOdd_TEMPLATE(u, 8);
____FUNCTION_DECLARATION_int_isOdd_TEMPLATE(u, 16);
____FUNCTION_DECLARATION_int_isOdd_TEMPLATE(u, 32);
____FUNCTION_DECLARATION_int_isOdd_TEMPLATE(u, 64);

____FUNCTION_DECLARATION_int_isOdd_TEMPLATE(s, 8);
____FUNCTION_DECLARATION_int_isOdd_TEMPLATE(s, 16);
____FUNCTION_DECLARATION_int_isOdd_TEMPLATE(s, 32);
____FUNCTION_DECLARATION_int_isOdd_TEMPLATE(s, 64);



#endif