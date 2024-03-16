#if !defined(____HEADER_GUARD_STRING_S_T_C)
#define ____HEADER_GUARD_STRING_S_T_C

#define ____STRING_S_T_USE_MEMORY_FIELD//optional, recommended for debugging.

#include "int_type.h"



typedef char ( *char_ptr_t );
typedef ui32_t string_length_t;

#if defined(____STRING_S_T_USE_MEMORY_FIELD)
typedef string_length_t string_memory_t;
#endif

typedef struct string_s_t { 
	char_ptr_t chars; 
	string_length_t len; 

	#if defined(____STRING_S_T_USE_MEMORY_FIELD)
	string_memory_t mem; 
	#endif

	string_length_t index; 
} string_s_t;

typedef string_s_t ( *string_s_ptr_t );



#endif