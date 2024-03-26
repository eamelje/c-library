#define convert(oldValue, newType) \
________conv_ ## \
________getConv(typeof(oldValue),newType) ## \
(oldValue,newType)


#include "int_type.h"
#include "exit_status_type.h"


#define ________convert_simple(oldValue,newType) \
((newType)oldValue)


#define ________convert_simple_unsafe(oldValue,newType) /*idk*/


#define ________convert_maybeUnderflow(oldValue,newType) \
(oldValue<0)\
?\
{fprintf(stderr,"can't assign negative value to unsigned integer .\n"), exit(exitStatus_failure), 0}\
:\
________convert_simple(oldValue,newType)



#define maybeOverflow

#define ________convert_complex(typeof(oldValue,newType) \ ________convert_complex_ ## \
typeof(oldValue) ## \
_ ## \
newType ## \
( ## oldValue ## )


#define ________getConv(oldType, newType) \
________convertMode ## _oldType_ ## newType

#define ________convertMode_ui8_t_ui8_t nothing
#define ________convertMode_ui8_t_ui16_t simple
#define ________convertMode_ui8_t_ui32_t simple
#define ________convertMode_ui8_t_ui64_t simple

#define ________convertMode_ui16_t_ui8_t simple_unsafe
#define ________convertMode_ui16_t_ui16_t nothing
#define ________convertMode_ui16_t_ui32_t simple
#define ________convertMode_ui16_t_ui64_t simple

#define ________convertMode_ui32_t_ui8_t simple_unsafe
#define ________convertMode_ui32_t_ui16_t simple_unsafe
#define ________convertMode_ui32_t_ui32_t nothing
#define ________convertMode_ui32_t_ui64_t simple

#define ________convertMode_ui64_t_ui8_t simple_unsafe
#define ________convertMode_ui64_t_ui16_t simple_unsafe
#define ________convertMode_ui64_t_ui32_t simple_unsafe
#define ________convertMode_ui64_t_ui64_t nothing



#define ________convertMode_si8_t_si8_t nothing
#define ________convertMode_si8_t_si16_t simple
#define ________convertMode_si8_t_si32_t simple
#define ________convertMode_si8_t_si64_t simple

#define ________convertMode_si16_t_si8_t simple_unsafe
#define ________convertMode_si16_t_si16_t nothing
#define ________convertMode_si16_t_si32_t simple
#define ________convertMode_si16_t_si64_t simple

#define ________convertMode_si32_t_si8_t simple_unsafe
#define ________convertMode_si32_t_si16_t simple_unsafe
#define ________convertMode_si32_t_si32_t nothing
#define ________convertMode_si32_t_si64_t simple

#define ________convertMode_si64_t_si8_t simple_unsafe
#define ________convertMode_si64_t_si16_t simple_unsafe
#define ________convertMode_si64_t_si32_t simple_unsafe
#define ________convertMode_si64_t_si64_t nothing



#define ________convertMode_ui8_t_si8_t simple_unsafe
#define ________convertMode_ui8_t_si16_t simple
#define ________convertMode_ui8_t_si32_t simple
#define ________convertMode_ui8_t_si64_t simple

#define ________convertMode_ui16_t_si8_t simple_unsafe
#define ________convertMode_ui16_t_si16_t simple_unsafe
#define ________convertMode_ui16_t_si32_t simple
#define ________convertMode_ui16_t_si64_t simple

#define ________convertMode_ui32_t_si8_t simple_unsafe
#define ________convertMode_ui32_t_si16_t simple_unsafe
#define ________convertMode_ui32_t_si32_t simple_unsafe
#define ________convertMode_ui32_t_si64_t simple

#define ________convertMode_ui64_t_si8_t simple_unsafe
#define ________convertMode_ui64_t_si16_t simple_unsafe
#define ________convertMode_ui64_t_si32_t simple_unsafe
#define ________convertMode_ui64_t_si64_t simple_unsafe




#define ________convertMode_si8_t_ui8_t maybeUnderflow
#define ________convertMode_si8_t_ui16_t maybeUnderflow
#define ________convertMode_si8_t_ui32_t maybeUnderflow
#define ________convertMode_si8_t_ui64_t maybeUnderflow

#define ________convertMode_si16_t_ui8_t maybeUnderflow
#define ________convertMode_si16_t_ui16_t maybeUnderflow
#define ________convertMode_si16_t_ui32_t maybeUnderflow
#define ________convertMode_si16_t_ui64_t maybeUnderflow

#define ________convertMode_si32_t_ui8_t maybeUnderflow
#define ________convertMode_si32_t_ui16_t maybeUnderflow
#define ________convertMode_si32_t_ui32_t maybeUnderflow
#define ________convertMode_si32_t_ui64_t maybeUnderflow

#define ________convertMode_si64_t_ui8_t maybeUnderflow
#define ________convertMode_si64_t_ui16_t maybeUnderflow
#define ________convertMode_si64_t_ui32_t maybeUnderflow
#define ________convertMode_si64_t_ui64_t maybeUnderflow

