#if !defined()
#define



typedef enum MATH_S_STATUS_TYPE
{
math_s_status_success,
math_s_status_overflow,
math_s_status_underflow
}
math_s_status_type;




____math_s_decl_errArgs \
math_s_status_type *Out_status_Nullable,\
bool In_exitIfOverflow,\
bool In_exitIfUnderflow,\
bool *Out_didExit_Nullable\



____math_s_int_decl_part1_template(name_,suffix_,returnType_) \
__ ## attributes ## __ \
(( ## __ ## always_inline ## __ ## )) \
inline \
returnType_ \
math_s_int_ ## name_ ## _ ## returnType_ ## _ ## suffix_



#define ____math_s_int_decl_args_2arg_template(argType_) \
(\
argType_ x,\
argType_ y,\
____math_s_decl_errArgs\
)



____math_s_decl_full_2arg_template(name_,suffix_,type_) \
____math_s_int_decl_part1_template(name_,suffix_,type_) \
____math_s_int_decl_args_2arg_template(type_)





math_s_int_log()
math_s_int_root()
math_s_int_sin()
math_s_int_cos()
math_s_int_floor()
math_s_int_ceiling()
math_s_int_round()
math_s_int_add()
math_s_int_sub()
math_s_int_mul()
math_s_int_div()
math_s_int_mod()



math_s_flp_exp(x,y,statusptr_Nullable)





#endif