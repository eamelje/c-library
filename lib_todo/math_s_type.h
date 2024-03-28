#if !defined(____HEADER_GUARD_math_s_type_h)
#define ____HEADER_GUARD_math_s_type_h



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



#endif
