#if !defined(____HEADER_GUARD_BOOL_T__C)
#define ____HEADER_GUARD_BOOL_T__C



#if !defined(bool)
#define ____bool_was_not_defined
#endif


#if !defined(bool) && !defined(true) && !defined(false)
	typedef enum bool{ false = 0, true = 1 } bool;
#define ____bool_defined_as_enum 1
#endif



#if defined(____bool_defined_as_enum) && ____bool_defined_as_enum <= 0
#undef ____bool_defined_as_enum
#endif



#if defined(____bool_was_not_defined) && bool_was_not_defined <= 0
#undef bool_was_not_defined
#endif



#if !defined(____bool_defined_as_enum)


#if !defined(true)
#define true 1
#endif

#if !defined(false)
#define false 0
#endif

#if !defined(bool)
#define bool unsigned char
#endif


#endif



#if defined(____bool_defined_as_enum)
	typedef bool bool_t;
#else
#define bool_t bool
#endif



#if defined(bool_was_not_defined)
#undef bool_was_not_defined
#endif



#endif