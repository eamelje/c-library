#if !defined(____HEADER_GUARD_GETTOKEN_C)
#define ____HEADER_GUARD_GETTOKEN_C



#define ____TRYGETTOKEN_IMMEDIATESTRING_FUNCTION_DECLARATION \
exitStatus_t \
compiler_tryGetToken_immediateString\
(\
string_s_t sourceCode, \
ui32_t *sourceCodeIndex,\
tokenStack_type *tokenStack\
)



____GETTOKEN_FUNCTION_DECLARATION;



#endif