#include "string_s_cat.h"



//#include <stdio.h>//temp for debug



____string_s_cat_function_declaration{

ui32_t b_len;

if(b_len_nullable == 0)
{
	if (b.len <= 0) 
	{
		b_len = string_s_len(b);
	}	else {
		b_len = b.len;
	}
} else {
	b_len = b_len_nullable;
}


if((*a).len <= 0)
{
	(*a).len = string_s_len((*a));
}

ui32_t a_len_new = (*a).len + b_len;
ui32_t a_mem_req = a_len_new + 1;/*+1 for null termination*/

if(
	#if defined(____STRING_S_T_USE_MEMORY_FIELD)
	(unsigned char)1
	#else
	(*a).mem <= a_mem_req
	#endif
	)
{
	string_s_realloc ((*a), a_mem_req, a);
//					printf("string_s_cat.c reallocating 'a'\n");//temp for debug
}


ui32_t 
	a_index_max_old = (*a).len - 1,
	a_index = a_index_max_old + 1,
	b_index_max = b_len - 1,
	b_index = 0,
	a_index_max_new = a_len_new - 1;/*-1 for len to index*/

while(b_index <= b_index_max && a_index <= a_index_max_new)
{
	(*a).chars[a_index] = b.chars[b_index];
	a_index++;
	b_index++;
}

(*a).chars[a_index_max_new + 1] = '\0';
(*a).len = a_len_new;
(*a).index = 0;

return;
}