#if !defined()
#define



typedef enum MATH_S_STATUS_TYPE
{
math_s_status_success,
math_s_status_overflow,
math_s_status_underflow
}
math_s_status_type;

___errargs (status, bool exitearly)

____math_s_int_decl_part1_template(name_,suffix_,returnType_) \
__ ## attributes ## __ ## (( ## __ ## always_inline ## __ ## )) inline \
returnType_ math_s_int_ ## name_ ## _ ## returnType_ ## _ ## suffix_

#define ____math_s_int_decl_part2_2arg_template(argType_) \
( argType_ x, argType_ y, math_s_status_type *statusPtr_Nullable )

____math_s_decl_full_2arg_template(name_,suffix_,returnType_,argType) \
part1() \
part2_2arg()



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