#include "file_exists.h"


#if !defined(_CRT_SECURE_NO_WARNINGS)
#define _FILE_EXISTS_DEFINED__CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>



#if !defined(NULL)
#define ____FILE_EXISTS_DEFINED_NULL
#define NULL ((void *)0)
#endif



____FILE_EXISTS_FUNCTION_DECLARATION
{



FILE *f = fopen(path, "rb");



if (f == NULL){return false;}
else{fclose(f); return true;}



}



#if defined(____FILE_EXISTS_DEFINED_NULL)
#undef ____FILE_EXISTS_DEFINED_NULL
#undef NULL
#endif



#if defined(_FILE_EXISTS_DEFINED__CRT_SECURE_NO_WARNINGS)
#undef _FILE_EXISTS_DEFINED__CRT_SECURE_NO_WARNINGS
#undef _CRT_SECURE_NO_WARNINGS
#endif