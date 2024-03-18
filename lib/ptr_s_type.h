#if !defined(____HEADER_GUARD_PTR_S_TYPE_C)
#define ____HEADER_GUARD_PTR_S_TYPE_C



#include "int_type.h"



typedef void (*ptr_t);



//typedef struct {ptr_t p; ui8_t s;} ptr8_s_t;
//typedef struct {ptr_t p; ui16_t s;} ptr16_s_t;
typedef struct {ptr_t p; ui32_t s;} ptr32_s_t;
//typedef struct {ptr_t p; ui64_t s;} ptr64_s_t;



#endif