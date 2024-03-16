#if !defined(____HEADER_GUARD_EXIT_MACROS_C)
#define ____HEADER_GUARD_EXIT_MACROS_C



#if !defined(EXIT_FAILURE)
#define EXIT_FAILURE 1
#endif



#if !defined(EXIT_SUCCESS)
#define EXIT_SUCCESS 0
#endif



#define exitStatus_failure EXIT_FAILURE
#define exitStatus_success EXIT_SUCCESS
#define exitStatus_unknown exitStatus_success



typedef unsigned char exitStatus_t;



#endif