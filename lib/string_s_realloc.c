#include "string_s_realloc.h"


#if 0//old impl, date time < 2024/03/07 00:00 // no longer compatible as of 2024-03-09 19:36, due to conditional implementation of string type (mem field optional)
____STRING_S_REALLOC_FUNCTION_DECLARATION{

string_s_t r = (string_s_t){.mem = new_string_mem, .len = 0, .index = 0};

r.chars = realloc (string.chars, new_string_mem);

if ( new_string_mem < string.len ) 
{ 
	r.len = new_string_mem - 1; 
	r.chars[r.len - 1 + 1] = '\0'; 
} else { 
	r.len = string.len; 
}

if ( string.index > (r.len - 1) ) 
{
	r.index = r.len; 
} else {
	r.len = string.len;
	r.index = string.index;
}

if(string.chars == (*dst).chars)/*if realloc to self, prevent memory leak*/
{
	free((*dst).chars);
	(*dst).chars = NULL;
}

(*dst) = r;
return;
}
#endif



#if 1//new impl, date time = 2024/03/07 08:08
____STRING_S_REALLOC_FUNCTION_DECLARATION{
string_s_t r = (string_s_t){
	#if defined(____string_s_____STRING_S_T_USE_MEMORY_FIELD)
	.mem = new_string_mem, 
	#endif
	.len = 0, .index = 0};

r.index = string.index;

r.chars = calloc(new_string_mem * sizeof(char), sizeof(char));
r.len = string.len;

ui32_t index = 0, index_max = string.len - 1;

_LOOP:
r.chars[index] = string.chars[index];
index++;
if(index <= index_max)
goto _LOOP;

if(string.chars == (*dst).chars)/*if realloc to self, prevent memory leak*/
{
	free((*dst).chars);
	(*dst).chars = NULL;
}

(*dst).chars = r.chars;
(*dst).len = r.len;
(*dst).index = string.index;
#if defined(____STRING_S_T_USE_MEMORY_FIELD)
(*dst).mem = r.mem;
#endif
return;
}
#endif
