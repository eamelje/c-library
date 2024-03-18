#include "ptr_s_malloc.h"


#include <malloc.h>




____ptr_s_malloc_function_declaration
{



if(size <= 0)
{
	ptr->s = 0; 
	ptr->p = NULL; 
	return;
}



_LABEL_A:


if(ptr->p != NULL)
{
	free(ptr->p);
}



ptr->p = malloc(size);



if(ptr->p == NULL)
{
	goto _LABEL_A;
}



ptr->s = size;



return;



}



____ptr_s_free_function_declaration
{



free(ptr->p);



ptr->s = 0;



return;



}


