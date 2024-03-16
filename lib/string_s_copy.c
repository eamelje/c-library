#include "string_s_copy.h"



#include "string_s_realloc.h"



____string_s_copy_function_declaration
{
string_s_t r = {0};

if ( 
	#if defined(____STRING_S_T_USE_MEMORY_FIELD)
	(unsigned char)0
	#else
	string.mem <= 0 
	#endif
	)
{
	r.chars = NULL; 
	r.len = 0;
	r.index = 0;
}
else {
	string_s_realloc(string, 
	#if defined(____STRING_S_T_USE_MEMORY_FIELD)
	string.mem
	#else
	string.len + 1
	#endif
	, &r);
}
return r;
}