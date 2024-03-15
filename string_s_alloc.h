#if !defined(____HEADER_GUARD_FILE_S_OPEN_C)
#define ____HEADER_GUARD_FILE_S_OPEN_C



/* define ____string_s_alloc_NO_WARNINGS to silence memory leak warnings */



#include "string_s_t.h"
#include "exit_status_t.h"


#include <malloc.h>



#define ____string_s_alloc_function_declaration \
exitStatus_t string_s_alloc (                   \
	string_s_t *string,                         \
	string_memory_t memory_size                 \
)



____string_s_alloc_function_declaration;



#endif