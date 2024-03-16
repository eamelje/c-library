#if !defined(____HEADER_GUARD_STRING_S_IS__C)
#define ____HEADER_GUARD_STRING_S_IS__C



#include "string_s_type.h"
#include "char_is_.h"
#include "bool_type.h"



#define ____string_s_is__function_declaration \
bool ____string_s_is__template\
(\
string_s_t string, \
bool (*char_is__function_ptr)(char)\
)



____string_s_is__function_declaration;



#define ____string_s_is_lower_function_declaration bool string_s_is_lower(string_s_t string)
#define ____string_s_is_upper_function_declaration bool string_s_is_upper(string_s_t string)
#define ____string_s_is_alpha_function_declaration bool string_s_is_alpha(string_s_t string)
#define ____string_s_is_digit_function_declaration bool string_s_is_digit(string_s_t string)
#define ____string_s_is_alphanumeric_function_declaration bool string_s_is_alphanumeric(string_s_t string)
#define ____string_s_is_whitespace_function_declaration bool string_s_is_whitespace(string_s_t string)
#define ____string_s_is_escapeChar_function_declaration bool string_s_is_escapeChar(string_s_t string)



____string_s_is_lower_function_declaration;
____string_s_is_upper_function_declaration;
____string_s_is_alpha_function_declaration;
____string_s_is_digit_function_declaration;
____string_s_is_alphanumeric_function_declaration;
____string_s_is_whitespace_function_declaration;
____string_s_is_escapeChar_function_declaration;



#endif