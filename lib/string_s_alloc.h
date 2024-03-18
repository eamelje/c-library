#if !defined(____HEADER_GUARD_STRING_S_ALLOC_C)
#define ____HEADER_GUARD_STRING_S_ALLOC_C



/* define ____string_s_alloc_NO_WARNINGS to silence memory leak warnings */



#include "string_s_type.h"
#include "exit_status_type.h"


#include <malloc.h>



#define ____string_s_alloc_function_declaration \
exitStatus_t string_s_alloc (                   \
	string_s_t *string,                         \
	string_memory_t memory_size                 \
)



____string_s_alloc_function_declaration;



#endif