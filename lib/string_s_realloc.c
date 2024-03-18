#define ____STRING_S_REALLOC_DEBUG



#include "string_s_realloc.h"



#if !defined(NULL)
#define ____STRING_S_REALLOC_DEFINED_NULL
#define NULL ((void *)0)
#endif



#if defined(____STRING_S_REALLOC_DEBUG)
#include <stdio.h>
#define ___DEBUG_PRINT_LINE(line) fprintf(stderr,"[DEBUG] :  file :  string_s_realloc.c .  line :  %i .  \n", line);
#endif



//new impl, date time = 2024/03/07 08:08
____STRING_S_REALLOC_FUNCTION_DECLARATION{



string_s_t r;
#if defined(____string_s_____STRING_S_T_USE_MEMORY_FIELD)
r.mem = new_string_mem;
#endif
r.len = 0; 
r.index = 0;
r.index = string.index;
r.chars = NULL;


					#if defined(____STRING_S_REALLOC_DEBUG)
					___DEBUG_PRINT_LINE(__LINE__)
					#endif


if(new_string_mem <= 0)
{
	*dst = r;
	return;
}


					#if defined(____STRING_S_REALLOC_DEBUG)
					___DEBUG_PRINT_LINE(__LINE__)
					#endif


r.chars = calloc(new_string_mem * sizeof(char), sizeof(char));
r.len = string.len;


					#if defined(____STRING_S_REALLOC_DEBUG)
					___DEBUG_PRINT_LINE(__LINE__)
					#endif


ui32_t index = 0, index_max;
if(string.len < 1){index_max = 0;}
else {index_max = string.len - 1;}


					#if defined(____STRING_S_REALLOC_DEBUG)
					___DEBUG_PRINT_LINE(__LINE__)
					fprintf(stderr,"[DEBUG] :  string.len = %i .  \n",(int)string.len);
					#endif


_LOOP:


					#if defined(____STRING_S_REALLOC_DEBUG)
					___DEBUG_PRINT_LINE(__LINE__)
					fprintf(stderr,"[DEBUG] :  index = %i ,  index_max = %i ,  r.chars[index] = '%c' (%i) .  \n", (int)index, (int)index_max, r.chars[index], r.chars[index]);

					#endif


r.chars[index] = string.chars[index];
index++;
if(index <= index_max)
{goto _LOOP;}


					#if defined(____STRING_S_REALLOC_DEBUG)
					___DEBUG_PRINT_LINE(__LINE__)
					#endif


if(string.chars == (*dst).chars)/*if realloc to self, free first to prevent memory leak*/
{
	free(dst->chars);
	dst->chars = NULL;
}


					#if defined(____STRING_S_REALLOC_DEBUG)
					___DEBUG_PRINT_LINE(__LINE__)
					#endif


dst->chars = r.chars;
dst->len = r.len;
dst->index = string.index;
#if defined(____STRING_S_T_USE_MEMORY_FIELD)
dst->mem = r.mem;
#endif


					#if defined(____STRING_S_REALLOC_DEBUG)
					___DEBUG_PRINT_LINE(__LINE__)
					#endif


return;



}



#if defined(____STRING_S_REALLOC_DEFINED_NULL)
#undef ____STRING_S_REALLOC_DEFINED_NULL
#undef NULL
#endif