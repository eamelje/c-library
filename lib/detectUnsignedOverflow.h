#if !defined(____HEADER_GUARD_detectUnsignedOverflow_h)
#define ____HEADER_GUARD_detectUnsignedOverflow_h



#include "bool_type.h"
#include "int_type.h"



#define ____FUNCTION_DECLARATION_detectUnsignedAdditionOverflow_TEMPLATE(size_) \
bool \
detectUnsignedAdditionOverflow ## size_ \
(\
ui ## size_ ## _t a,\
ui ## size_ ## _t b\
)



#define ____FUNCTION_BODY_detectUnsignedAdditionOverflow_TEMPLATE(size_) \
{\
\
\
\
return ((a + b) < a);\
\
\
\
}



____FUNCTION_DECLARATION_detectUnsignedAdditionOverflow_TEMPLATE(8);
____FUNCTION_DECLARATION_detectUnsignedAdditionOverflow_TEMPLATE(16);
____FUNCTION_DECLARATION_detectUnsignedAdditionOverflow_TEMPLATE(32);
____FUNCTION_DECLARATION_detectUnsignedAdditionOverflow_TEMPLATE(64);



#endif