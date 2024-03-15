#include "string_s_free.h"



#include <malloc.h>



____STRING_S_FREE_FUNCTION_DECLARATION{

free ( (void *)((*string).chars) );

#if defined(____STRING_S_T_USE_MEMORY_FIELD)
(*string).mem = 0;
#endif
(*string).chars = NULL;
(*string).len = 0;
(*string).index = 0;

return;
}