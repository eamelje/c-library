#if !defined(____HEADER_GUARD_INT_T_C)
#define ____HEADER_GUARD_INT_T_C



typedef unsigned long long int ui64_t;
typedef unsigned long int ui32_t;
typedef unsigned short int ui16_t;
typedef unsigned char ui8_t;


typedef signed long long int si64_t;
typedef signed long int si32_t;
typedef signed short int si16_t;
typedef signed char si8_t;



#define ui64_max 0xffffffffffffffff
#define ui32_max 0xffffffff
#define ui16_max 0xffff
#define ui8_max 0xff

#define ui64_min 0
#define ui32_min 0
#define ui16_min 0
#define ui8_min 0


#define si64_max 0x7fffffffffffffff
#define si32_max 0x7fffffff
#define si16_max 0x7fff
#define si8_max 0x7f

#define si64_min -0x8000000000000000
#define si32_min -0x80000000
#define si16_min -0x8000
#define si8_min -0x80




#endif