#if !defined(____HEADER_GUARD_STRING_S_CAT_C)
#define ____HEADER_GUARD_STRING_S_CAT_C



#include "string_s_t.h"
#include "string_s_len.h"
#include "string_s_realloc.h"



#define ____string_s_cat_function_declaration \
void string_s_cat\
(\
string_s_t *a, \
string_s_t b, \
ui32_t b_len_nullable\
)



____string_s_cat_function_declaration;



#endif