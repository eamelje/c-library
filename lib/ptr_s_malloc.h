#if !defined(____HEADER_GUARD_MALLOC_S_C)
#define ____HEADER_GUARD_MALLOC_S_C



#include "ptr_s_type.h"



#define ____ptr_s_malloc_function_declaration \
void ptr_s_malloc(ptr32_s_t *ptr, ui32_t size)


____ptr_s_malloc_function_declaration;



#define ____ptr_s_free_function_declaration \
void ptr_s_free(ptr32_s_t *ptr)


____ptr_s_free_function_declaration;



#endif