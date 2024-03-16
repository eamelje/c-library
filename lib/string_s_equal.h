#if !defined(____HEADER_GUARD_STRING_S_EQUAL_C)
#define ____HEADER_GUARD_STRING_S_EQUAL_C



#include "bool_type.h"
#include "int_type.h"
#include "string_s_type.h"



#define ____string_s_equal_function_declaration \
bool string_s_equal\
(\
string_s_t a, \
string_s_t b, \
ui32_t a_index_offset, \
ui32_t b_index_offset, \
ui32_t len_nullable\
)



____string_s_equal_function_declaration;



#endif