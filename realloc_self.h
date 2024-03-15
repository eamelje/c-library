#if !defined(____HEADER_GUARD_REALLOC_SELF_C)
#define ____HEADER_GUARD_REALLOC_SELF_C



#include "int_t.h"


#include <malloc.h>



#define ____realloc_self_function_declaration \
void realloc_self\
(\
void **ptr, \
ui64_t allocsz\
)



____realloc_self_function_declaration;



#endif