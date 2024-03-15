#include "string_s_assignImmediate.h"



#include "char_ptr_len.h"



#include <malloc.h>



/* need to implement as malloc/calloc instead of realloc, otherwise runtime crashes*/
____string_s_assignImmediate_function_declaration{
string_s_t r = (string_s_t){
.chars = NULL, .len = 0, 
#if defined(____STRING_S_T_USE_MEMORY_FIELD)
.mem = 0,
#endif
.index = 0};

r.len = char_ptr_len ( chars );
#if defined(____STRING_S_T_USE_MEMORY_FIELD)
r.mem = r.len + 1;
#endif
r.chars = calloc( 
#if defined(____STRING_S_T_USE_MEMORY_FIELD)
r.mem 
#else
(r.len + 1)
#endif
* sizeof(char), sizeof(char) );
ui32_t r_index_max = r.len - 1;
goto _LOOP;

_LOOP:
r.chars[r.index] = chars[r.index];
r.index++;
if(r.index <= r_index_max && chars[r.index] != '\0')
{
	goto _LOOP;
} else {
	r.chars[r_index_max + 1] = '\0';
	r.index = 0;
	return r;
}
}