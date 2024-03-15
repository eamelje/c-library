#include "char_ptr_len.h"



____char_ptr_len_function_declaration
{
	ui32_t a = 0;
	while ( char_ptr[ a ] != '\0' )
	{
		a++;
	}
	return a;
}