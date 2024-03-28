#if !defined(____HEADER_GUARD_MATH_S_FUNC_UTILS_H)
#define ____HEADER_GUARD_MATH_S_FUNC_UTILS_H



#define ____math_s_function_name_GET_SUFFIX(suffix_) ____math_s_function_name_suffix_ ## suffix_



#define ____math_s_decl_argsCore \
math_s_status_type *Out_status_Nullable,\
bool *Out_didExit_Nullable,\
bool In_exitIfOverflow,\
bool In_exitIfUnderflow\




#define ____math_s_decl_attributes \
__ ## attribute ## __ \
(( ## __ ## always_inline ## __ ## )) \
inline



#define ____math_s_decl_name(operation_name_,typeName_,suffix_) \
math_s_int_ ## \
operation_name_ ## \
_ ## \
typeName_ ## \
suffix_



#endif