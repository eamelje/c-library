#if !defined(____HEADER_GUARD_FREAD_S_STRING_S_C)
#define ____HEADER_GUARD_FREAD_S_STRING_S_C



#include "string_s_type.h"
#include "int_type.h"
#include "file_s_type.h"
#include "string_s_realloc.h"
#include "string_s_concatenate.h"
#include "string_s_free.h"


#include <stdio.h>



#if defined(____FREAD_S_BUFFER_SIZE) && (____FREAD_S_BUFFER_SIZE <= 128)
#warning ____FREAD_S_BUFFER_SIZE is too small. Redefining as 128.
#undef ____FREAD_S_BUFFER_SIZE
#define ____FREAD_S_BUFFER_SIZE ((unsigned char)128)
#endif


#if !defined(____FREAD_S_BUFFER_SIZE)
#define ____FREAD_S_BUFFER_SIZE ((unsigned short int)1024)
#endif



typedef enum fread_s_string_s_mode_t {
fread_s_string_s_mode_append, 
fread_s_string_s_mode_overwrite
} fread_s_string_s_mode_t;


#define ____FREAD_S_STRING_S_LEN_TYPE ui32_t


#define ____FREAD_S_STRING_S_FUNCTION_DECLARATION \
____FREAD_S_STRING_S_LEN_TYPE fread_s_string_s\
(\
string_s_t *buf, \
fread_s_string_s_mode_t mode, \
____FREAD_S_STRING_S_LEN_TYPE read_len, \
file_s_t *stream\
)



____FREAD_S_STRING_S_FUNCTION_DECLARATION;



#endif