#if !defined(____HEADER_GUARD_math_s_type_h)
#define ____HEADER_GUARD_math_s_type_h



#include "int_type.h"



typedef enum MATH_S_STATUS_TYPE
{
	math_s_status_success,
	math_s_status_overflow,
	math_s_status_underflow
}
math_s_status_type;



typedef enum MATH_S_RETURNmODE_TYPE
{
	math_s_returnMode_noReturn,
	math_s_returnMode_limit/*min value if underflow, max value if overflow, undefined otherwise*/,
	math_s_returnMode_recent/*most recently calculated value before erronous behaviour*/
}
math_s_returnMode_type;




#define ____math_s_function_name_GET_SUFFIX(suffix_) ____math_s_function_name_suffix_ ## suffix_


#define ____math_s_function_name_suffix_noSuffix
#define ____math_s_function_name_suffix_safe _safe
#define ____math_s_function_name_suffix_fast _fast



#define ____math_s_decl_argsCore \
math_s_status_type *Out_status_Nullable,\
bool *Out_didExit_Nullable,\
bool In_exitIfOverflow,\
bool In_exitIfUnderflow\




#define ____math_s_decl_attributes \
__ ## attributes ## __ \
(( ## __ ## always_inline ## __ ## )) \
inline



#define ____math_s_decl_name(operation_name_,typeName_,suffix_) \
math_s_int_ ## \
operation_name_ ## \
_ ## \
typeName_ ## _t ## \
____math_s_function_name_GET_SUFFIX(suffix_)



/*exponentiate*/


#define ____FUNCTION_DECLARATION_math_s_decl_exp_name exp


#define ____FUNCTION_DECLARATION_math_s_decl_exp_ui8 \
____math_s_decl_attributes \
____math_s_decl_name(____FUNCTION_DECLARATION_math_s_decl_exp_name, ui8, noSuffix) \
/*args*/(____math_s_decl_argsCore, ui8_t a, ui8_t b)


#define ____FUNCTION_DECLARATION_math_s_decl_exp_ui16 \
____math_s_decl_attributes \
____math_s_decl_name(____FUNCTION_DECLARATION_math_s_decl_exp_name, ui16, noSuffix) \
/*args*/(____math_s_decl_argsCore, ui16_t a, ui16_t b)


#define ____FUNCTION_DECLARATION_math_s_decl_exp_ui8 \
____math_s_decl_attributes \
____math_s_decl_name(____FUNCTION_DECLARATION_math_s_decl_exp_name, ui32, noSuffix) \
/*args*/(____math_s_decl_argsCore, ui32_t a, ui32_t b)


#define ____FUNCTION_DECLARATION_math_s_decl_exp_ui64 \
____math_s_decl_attributes \
____math_s_decl_name(____FUNCTION_DECLARATION_math_s_decl_exp_name, ui64, noSuffix) \
/*args*/(____math_s_decl_argsCore, ui64_t a, ui64_t b)



/* ceiling */


#define ____FUNCTION_DECLARATION_math_s_decl_ceil_name ceil


#define ____FUNCTION_DECLARATION_math_s_decl_ceil_ui8 \
____math_s_decl_attributes \
____math_s_decl_name(____FUNCTION_DECLARATION_math_s_decl_ceil_name, ui8, noSuffix) \
/*args*/(____math_s_decl_argsCore, ui8_t a, ui8_t b)


#define ____FUNCTION_DECLARATION_math_s_decl_ceil_ui16 \
____math_s_decl_attributes \
____math_s_decl_name(____FUNCTION_DECLARATION_math_s_decl_ceil_name, ui16, noSuffix) \
/*args*/(____math_s_decl_argsCore, ui16_t a, ui16_t b)


#define ____FUNCTION_DECLARATION_math_s_decl_ceil_ui8 \
____math_s_decl_attributes \
____math_s_decl_name(____FUNCTION_DECLARATION_math_s_decl_ceil_name, ui32, noSuffix) \
/*args*/(____math_s_decl_argsCore, ui32_t a, ui32_t b)


#define ____FUNCTION_DECLARATION_math_s_decl_ceil_ui64 \
____math_s_decl_attributes \
____math_s_decl_name(____FUNCTION_DECLARATION_math_s_decl_ceil_name, ui64, noSuffix) \
/*args*/(____math_s_decl_argsCore, ui64_t a, ui64_t b)



/* floor */


#define ____FUNCTION_DECLARATION_math_s_decl_floor_name floor


#define ____FUNCTION_DECLARATION_math_s_decl_floor_ui8 \
____math_s_decl_attributes \
____math_s_decl_name(____FUNCTION_DECLARATION_math_s_decl_floor_name, ui8, noSuffix) \
/*args*/(____math_s_decl_argsCore, ui8_t a, ui8_t b)


#define ____FUNCTION_DECLARATION_math_s_decl_floor_ui16 \
____math_s_decl_attributes \
____math_s_decl_name(____FUNCTION_DECLARATION_math_s_decl_floor_name, ui16, noSuffix) \
/*args*/(____math_s_decl_argsCore, ui16_t a, ui16_t b)


#define ____FUNCTION_DECLARATION_math_s_decl_floor_ui8 \
____math_s_decl_attributes \
____math_s_decl_name(____FUNCTION_DECLARATION_math_s_decl_floor_name, ui32, noSuffix) \
/*args*/(____math_s_decl_argsCore, ui32_t a, ui32_t b)


#define ____FUNCTION_DECLARATION_math_s_decl_floor_ui64 \
____math_s_decl_attributes \
____math_s_decl_name(____FUNCTION_DECLARATION_math_s_decl_floor_name, ui64, noSuffix) \
/*args*/(____math_s_decl_argsCore, ui64_t a, ui64_t b)



/* log */
/* root */
/* sine */
/* cosine */
/* round */
/* add */
/* subtract */
/* multiply */
/* divide */
/* modulo */



#endif