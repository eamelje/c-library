#if !defined(____HEADER_GUARD_FILE_S_T_C)
#define ____HEADER_GUARD_FILE_S_T_C



#include "bool_t.h"


#include <stdio.h>



typedef enum file_s_status_t {
	file_s_status_openSuccess, 
	file_s_status_openFailure,
	file_s_status_closeSuccess,
	file_s_status_closeFailure,
	file_s_status_openFailure_alreadyOpen,
	file_s_status_unknown,
	____file_s_status_t_count
} file_s_status_t;



typedef FILE std_file_t;
typedef std_file_t ( *std_file_ptr_t );



typedef struct file_s_t { 
	std_file_ptr_t stdFile; 
	bool_t isOpen; 
	file_s_status_t status; 
} file_s_t;



#endif