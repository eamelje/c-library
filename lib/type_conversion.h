#define convert(oldValue, newType) \
________ ## conv ## ____getConv(typeof(oldValue),newValue) ##


#include "int_type.h"

#define ________convert_simple(oldValue, newType) ((newType)oldValue)
#define ________convert_simple_unsafe(


#define ____getConv(oldType, newType) \
________convCompl ## _oldType_ ## newType

#define ________convCompl_ui8_t_ui8_t simple
#define ui8_t_ui16_t
ui8_t_ui32_t
ui8_t_ui64_t

ui16_t_ui8_t simple_unsafe
ui16_t_ui16_t
ui16_t_ui32_t
ui16_t_ui64_t

