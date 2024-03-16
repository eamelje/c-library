#include "string_s_alloc.h"

#if !defined(____string_s_alloc_NO_WARNINGS)
#include "stdio.h"
#endif


____string_s_alloc_function_declaration{

#if !defined(____string_s_alloc_NO_WARNINGS)
exitStatus_t r = exitStatus_unknown;
#if defined(____STRING_S_T_USE_MEMORY_FIELD)
if((*string).mem != 0 || (*string).chars != NULL)
{
	fprintf(stderr,"[WARNING] :  function \"string_s_alloc\" may be leaking memory. Character pointer at address %p has not yet been deallocated.\n",(void *)((*string).chars));
	r = exitStatus_failure;
}
#endif
#endif

if(memory_size <= 0){(*string).chars = NULL;}
(*string).chars = calloc(memory_size * sizeof(char), sizeof(char));
#if defined(____STRING_S_T_USE_MEMORY_FIELD)
(*string).mem = memory_size;
#endif

#if !defined(____string_s_alloc_NO_WARNINGS)
if(r == exitStatus_failure){return r;}
else {return exitStatus_success;}
#else
return exitStatus_unknown;
#endif
}
