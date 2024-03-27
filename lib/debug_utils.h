#if !defined(____HEADER_GUARD_debug_utils_h)
#define ____HEADER_GUARD_debug_utils_h



#include <stdio.h>



#define ____DEBUG_PRINT(msg_, fileName_NULLABLE) \
fprintf(stderr,"[DEBUG] :  ");\
if(fileName_NULLABLE != NULL)\
{\
	fprintf(stderr, "file :  ");\
	fprintf(stderr, #fileName_NULLABLE, );\
	fprintf(stderr, " .  line :  %i .  ", (int)##__##LINE##__);\
}\
fprintf(stderr, msg_)








#endif