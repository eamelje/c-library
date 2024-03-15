#if !defined(____HEADER_GUARD_FILE_S_OPEN_C)
#define ____HEADER_GUARD_FILE_S_OPEN_C



#define _CRT_SECURE_NO_WARNINGS



#include "file_s_t.h"
#include "string_s_t.h"
#include "bool_t.h"
#include "exit_status_t.h"


#include <stdio.h>//fopen, fclose



typedef enum file_s_open_mode_t {
	file_s_open_mode_write_binary = 0, 
	file_s_open_mode_read_binary,
	____file_s_open_mode_t_count
} file_s_open_mode_t;



#define ____file_s_open_function_declaration    \
bool file_s_open (                              \
	file_s_t *file,                             \
	string_s_t path,                            \
	file_s_open_mode_t mode                     \
)



____file_s_open_function_declaration;



#define ____file_s_close_function_declaration    \
bool file_s_close (                              \
	file_s_t *file                               \
)



____file_s_close_function_declaration;



#endif