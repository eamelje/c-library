#if !defined(____HEADER_GUARD_int_isEven_h)
#define ____HEADER_GUARD_int_isEven_h



#include "bool_type.h"
#include "int_type.h"
#include "int_isOdd.h"



#define ____FUNCTION_DECLARATION_int_isEven_TEMPLATE(signLetter_, size_) \
__attribute__ ((__always_inline__)) inline \
bool \
signLetter_ ## i ## size_ ## _isOdd\
(\
signLetter_ ## i ## size_ ## _t int__\
)



#define ____FUNCTION_BODY_int_isEven_TEMPLATE(signLetter_, size_) \
{\
\
\
\
return (! signLetter_ ## i ## size_ ## _isOdd(int__));\
\
\
\
}



____FUNCTION_DECLARATION_int_isEven_TEMPLATE(u, 8);
____FUNCTION_DECLARATION_int_isEven_TEMPLATE(u, 16);
____FUNCTION_DECLARATION_int_isEven_TEMPLATE(u, 32);
____FUNCTION_DECLARATION_int_isEven_TEMPLATE(u, 64);

____FUNCTION_DECLARATION_int_isEven_TEMPLATE(s, 8);
____FUNCTION_DECLARATION_int_isEven_TEMPLATE(s, 16);
____FUNCTION_DECLARATION_int_isEven_TEMPLATE(s, 32);
____FUNCTION_DECLARATION_int_isEven_TEMPLATE(s, 64);



#endif