#if !defined(____HEADER_GUARD_STRING_S_REALLOC_C)
#define ____HEADER_GUARD_STRING_S_REALLOC_C



#include "string_s_type.h"


#include <malloc.h>



#define ____STRING_S_REALLOC_FUNCTION_DECLARATION \
void string_s_realloc\
(\
string_s_t string, \
string_memory_t new_string_mem, \
string_s_t *dst\
)



____STRING_S_REALLOC_FUNCTION_DECLARATION;



#endif