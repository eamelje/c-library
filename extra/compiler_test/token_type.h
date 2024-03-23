#if !defined(____HEADER_GUARD_TOKENTYPE_H)
#define ____HEADER_GUARD_TOKENTYPE_H



typedef enum tokenType_type {
	tt_immediateString = 0,
	tt_immediateInt64,
	tt_immediateInt32,
	tt_immediateInt16,
	tt_immediateInt8,
	tt_immediateFloat32,
	tt_immediateFloat64,
	tt_type,
	tt_var,
	tt_func,
	tt_macro,
	tt_functionName,
	tt_typeName,



	TT_COUNT
} tokenType_type;



typedef struct tokenData_type {
	tokenType_type type; 
	void *value;
} tokenData_type;



typedef struct tokenStack_type {
	tokenData_type *ptr;
	ui32_t index;
	ui32_t mem;
} tokenStack_type;



#endif