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



#define ____ui64_max_value 0xffffffffffffffff
#define ____ui32_max_value 0xffffffff
#define ____ui16_max_value 0xffff
#define ____ui8_max_value 0xff

#define ____ui64_min_value 0
#define ____ui32_min_value 0
#define ____ui16_min_value 0
#define ____ui8_min_value 0


#define ____si64_max_value 0x7fffffffffffffff
#define ____si32_max_value 0x7fffffff
#define ____si16_max_value 0x7fff
#define ____si8_max_value 0x7f

#define ____si64_min_value -0x8000000000000000
#define ____si32_min_value -0x80000000
#define ____si16_min_value -0x8000
#define ____si8_min_value -0x80



#if defined(____DEFINE_INT_LIMITS_AS_VARIABLES)



static ui64_t _ui64_max = ____ui64_max_value;
static ui32_t _ui32_max = ____ui32_max_value;
static ui16_t _ui16_max = ____ui16_max_value;
static ui8_t _ui8_max = ____ui8_max_value;

static ui64_t _ui64_min = ____ui64_min_value;
static ui32_t _ui32_min = ____ui32_min_value;
static ui16_t _ui16_min = ____ui16_min_value;
static ui8_t _ui8_min = ____ui8_min_value;


static si64_t _si64_max = ____si64_max_value;
static si32_t _si32_max = ____si32_max_value;
static si16_t _si16_max = ____si16_max_value;
static si8_t _si8_max = ____si8_max_value;

static si64_t _si64_min = ____si64_min_value;
static si32_t _si32_min = ____si32_min_value;
static si16_t _si16_min = ____si16_min_value;
static si8_t _si8_min = ____si8_min_value;



#else



#define _ui64_max ((ui64_t)____ui64_max_value)
#define _ui32_max ((ui32_t)____ui32_max_value)
#define _ui16_max ((ui16_t)____ui16_max_value)
#define _ui8_max ((ui8_t)____ui8_max_value)

#define _ui64_min ((ui64_t)____ui64_min_value)
#define _ui32_min ((ui32_t)____ui32_min_value)
#define _ui16_min ((ui16_t)____ui16_min_value)
#define _ui8_min ((ui8_t)____ui8_min_value)


#define _si64_max ((si64_t)____si64_max_value)
#define _si32_max ((si32_t)____si32_max_value)
#define _si16_max ((si16_t)____si16_max_value)
#define _si8_max ((si8_t)____si8_max_value)

#define _si64_min ((si64_t)____si64_min_value)
#define _si32_min ((si32_t)____si32_min_value)
#define _si16_min ((si16_t)____si16_min_value)
#define _si8_min ((si8_t)____si8_min_value)



#endif



#if 1


#undef ____ui64_max_value
#undef ____ui32_max_value
#undef ____ui16_max_value
#undef ____ui8_max_value

#undef ____ui64_min_value
#undef ____ui32_min_value
#undef ____ui16_min_value
#undef ____ui8_min_value


#undef ____si64_max_value
#undef ____si32_max_value
#undef ____si16_max_value
#undef ____si8_max_value

#undef ____si64_min_value
#undef ____si32_min_value
#undef ____si16_min_value
#undef ____si8_min_value


#endif


#endif