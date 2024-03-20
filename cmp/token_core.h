#if !defined(____HEADER_GUARD_TOKEN_CORE_H)
#define ____HEADER_GUARD_TOKEN_CORE_H



#if defined(____REQUIRE_WHITESPACE_BETWEEN_TOKENS) && ( ____REQUIRE_WHITESPACE_BETWEEN_TOKENS <= 0 )
#undef ____REQUIRE_WHITESPACE_BETWEEN_TOKENS
#endif



#define TOKEN_ESCAPEcHAR '\\'
#define TOKEN_STRINGsTART '"'
#define TOKEN_STRINGeND '"'
#define TOKEN_ESCAPED_CHAR_NEWlINE 'n'
#define TOKEN_ESCAPED_CHAR_TAB 't'
#define TOKEN_ESCAPED_CHAR_NULL '0'
#define TOKEN_ESCAPED_CHAR_ESCAPEcHAR TOKEN_ESCAPEcHAR
#define TOKEN_ESCAPED_CHAR_STRINGeND TOKEN_STRINGeND



#endif