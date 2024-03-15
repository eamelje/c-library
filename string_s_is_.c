#include "string_s_is_.h"



____string_s_is__function_declaration{
ui64_t index = 0;
ui64_t index_max = (ui64_t)(string.len - 1);

_LOOP:
if( !((*char_is__function_ptr)(string.chars[index])) )
{
	return false;
}
index++;
if(index <= index_max)
{
	goto _LOOP;
}
return true;
}



____string_s_is_lower_function_declaration{ return ____string_s_is__template ( string, ( &char_is_lower ) ); }
____string_s_is_upper_function_declaration{ return ____string_s_is__template ( string, ( &char_is_upper ) ); }
____string_s_is_alpha_function_declaration{ return ____string_s_is__template ( string, ( &char_is_alpha ) ); }
____string_s_is_digit_function_declaration{ return ____string_s_is__template ( string, ( &char_is_digit ) ); }
____string_s_is_alphanumeric_function_declaration{ return ____string_s_is__template ( string, ( &char_is_alphanumeric ) ); }
____string_s_is_whitespace_function_declaration{ return ____string_s_is__template ( string, ( &char_is_whitespace ) ); }
____string_s_is_escapeChar_function_declaration{ return ____string_s_is__template ( string, ( &char_is_escapeChar ) ); }