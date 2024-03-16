#include "string_s_equal.h"



//#include <stdio.h>//temp for debug


____string_s_equal_function_declaration{
if( len_nullable != 0 && ( len_nullable > a.len || len_nullable > b.len ) )
{
		//printf("ping start! %i\n",__LINE__);//temp for debug
	goto _f;
}

if(	(len_nullable == 0) && 
		(a_index_offset == b_index_offset) &&
		(a.len != b.len)
)
{
		//printf("ping start! %i ... a.len :  %llu, b.len :  %llu\n",__LINE__,(unsigned long long)a.len,(unsigned long long)b.len);//temp for debug
	goto _f;
}

if( len_nullable != 0 &&
	( 
		( ( a_index_offset + len_nullable ) > a.len ) || 
		( ( b_index_offset + len_nullable ) > b.len ) 
	)
)
{
		//printf("ping start! %i\n",__LINE__);//temp for debug
	goto _f;
}

else 
{
	goto _skip_f;
}

{
	_f:
	return false;
}

_skip_f:


ui32_t 
	a_index = a_index_offset, 
	b_index = b_index_offset,
	a_index_max,
	b_index_max,
	len;

if(len_nullable != 0)
{
	len = len_nullable;
	a_index_max = a_index_offset + len - 1;
	b_index_max = b_index_offset + len - 1;
} else {
	a_index_max = a.len - 1;
	b_index_max = b.len - 1;
}


_LOOP:

		//printf("[DEBUG] string_s_equal.c :  ('%c' == '%c') = %s\tindexes :  %llu, %llu\n", a.chars[a_index], b.chars[b_index], (a.chars[a_index]==b.chars[b_index]?"true":"false"),(unsigned long long)a_index,(unsigned long long)b_index);//temp for debug

if(a.chars[a_index] == b.chars[b_index] ) 
{
	if(a_index == a_index_max)
	{
					//printf("ping end true! %i\n",__LINE__);//temp for debug
		return true;
	} else {
		a_index++; 
		b_index++;
		goto _LOOP;
	}
} else {
			//printf("ping end false! %i\n",__LINE__);//temp for debug
	return false;
}
}
