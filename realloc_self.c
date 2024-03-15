#include "realloc_self.h"



____realloc_self_function_declaration{
if(allocsz <= 0 || (*ptr) == NULL)
{
	*ptr = NULL;
	return;
}
void *temp;
temp = *ptr;
*ptr = realloc(temp, allocsz);
free(temp);
temp = NULL;
return;
}