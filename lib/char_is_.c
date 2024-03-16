#include "char_is_.h"



#if 'a'<'z'
#define ____char_lower_min 'a'
#define ____char_lower_max 'z'
#else
#define ____char_lower_min 'z'
#define ____char_lower_max 'a'
#endif



#if 'A'<'Z'
#define ____char_upper_min 'A'
#define ____char_upper_max 'Z'
#else
#define ____char_upper_min 'Z'
#define ____char_upper_max 'A'
#endif



____char_is_lower_function_declaration{
return ( char_ >= ____char_lower_min
	&& char_ <= ____char_lower_max );
}



____char_is_upper_function_declaration{
	return ( char_ >= ____char_upper_min
		&& char_ <= ____char_upper_max );
}



____char_is_alpha_function_declaration{
	return ( char_is_upper ( char_ )
		|| char_is_lower ( char_ ) );
}



____char_is_whitespace_function_declaration{
	return ( char_ == ' '
		|| char_ == '\t'
		|| char_ == '\n' );
}



____char_is_alphanumeric_function_declaration{
	return ( char_is_alpha ( char_ ) || char_is_digit ( char_ ) );
}



____char_is_escapeChar_function_declaration{
return char_ == '\\'; 
}




/* isDigit */
#if !defined(____char_is_digit_function_body_is_defined) && '0'<'9' && '0'<'1' && '1'<'9'
#define ____char_is_digit_function_body_is_defined
____char_is_digit_function_declaration{ return ( char_ >= '0' && char_ <= '9' ); }
#endif


#if !defined(____char_is_digit_function_body_is_defined) && '0'>'9' && '0'>'1' && '1'<'9'
#define ____char_is_digit_function_body_is_defined
____char_is_digit_function_declaration{ return ( char_ >= '1' && char_ <= '0' ); }
#endif


#if !defined(____char_is_digit_function_body_is_defined) && '1'<'9'
#define ____char_is_digit_function_body_is_defined
____char_is_digit_function_declaration{ return ( ( char_ >= '1' && <= char_ '9' ) || char_ == '0' ); }
#endif


#if !defined(____char_is_digit_function_body_is_defined)
#define ____char_is_digit_function_body_is_defined
____char_is_digit_function_declaration{ return ( \
	char_ == '0' || char_ == '1' || char_ == '2' \
	|| char_ == '3' || char_ == '4' || char_ == '5' \
	|| char_ == '6' || char_ == '7' || char_ == '8' \
	|| char_ == '9' ); }
#endif/* isDigit */
