#include "file_find_depends.h"
#include "string_s_type.h"
#include "string_s_assignCharPtr.h"


#include <stdlib.h>/*for system function*/


____file_find_depends_function_declaration



#if defined(__POSIX__) && !defined(____FILE_FIND_DEPENDS_BODY_IS_DEFINED)

#define ____FILE_FIND_DEPENDS_BODY_IS_DEFINED



{
string_s_t r, str_tmp1, str_tmp2;
char *charPtr_tmp;

str_tmp1 = string_s_assignCharPtr("find ");
str_tmp2 = string_s_assignCharPtr(pattern);

string_s_cat(&str_tmp1, str_tmp2, 1);
string_s_free(&str_tmp2);

charPtr_tmp = system(str_tmp1.chars);
string_s_free(&str_tmp1);
str_tmp1 = string_s_assignCharPtr(charPtr_tmp);



free(charptr_tmp);

return str_tmp1;
}



#endif





#if !defined(____FILE_FIND_DEPENDS_BODY_IS_DEFINED)

#define ____FILE_FIND_DEPENDS_BODY_IS_DEFINED

{/*CURRENTLY NOT IMPLEMENTED, RETURNING NOTHING*/
string_s_t r;
r = string_s_assignCharPtr("");
return r;
}


#endif