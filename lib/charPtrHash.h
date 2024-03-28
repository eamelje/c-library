#if !defined(____HEADER_GUARD_charPtrHash_h)
#define ____HEADER_GUARD_charPtrHash_h



#include "../lib/int_isOdd.h"



#define ____FUNCTION_DECLARATION_TEMPLATE_charPtrHash(size_) \
ui ## size_ ## _t \
charPtrHash ## size_\
(\
char *charPtr,\
ui32_t ptrSize,\
ui32_t hashTableSize_Nullable\
)


#if 'a' < 'A'
#define ____202403231715_CHAR_MIN_VALUE 'a'
#else
#define ____202403231715_CHAR_MIN_VALUE 'A'
#endif
#define ____202403231715_MAGICVALUE (____202403231715_CHAR_MIN_VALUE - 1)


____FUNCTION_DECLARATION_TEMPLATE_charPtrHash(8);
____FUNCTION_DECLARATION_TEMPLATE_charPtrHash(16);
____FUNCTION_DECLARATION_TEMPLATE_charPtrHash(32);
____FUNCTION_DECLARATION_TEMPLATE_charPtrHash(64);



#define ____FUNCTION_BODY_TEMPLATE_charPtrHash(size_) \
{\
\
\
\
ui ## size_ ## _t proposed_hash = 0;\
ui32_t indexMax = ptrSize - 1, index = 0;\
ui8_t index_step_size;\
\
if(indexMax <= 25)\
{\
	index_step_size = 1;\
}\
else if(indexMax <= 100)\
{\
	index_step_size = 3;\
}\
else if(indexMax <= 250)\
{\
	index_step_size = 5;\
}\
else\
{\
	index_step_size = (ptrSize / 25);\
}\
\
\
\
if(\
	(hashTableSize_Nullable > 0)\
	&&\
	ui ## size_ ## _isOdd(hashTableSize_Nullable)\
)\
{\
proposed_hash += (_ui ## size_ ## _max_value / 2);\
}\
\
\
\
char tempChar;\
\
\
_LABEL_A:\
tempChar = (charPtr[index] - ____202403231715_MAGICVALUE);\
proposed_hash += tempChar;\
proposed_hash *= (tempChar % 7);\
if(index <= indexMax)\
{\
	index += index_step_size;\
	goto _LABEL_A;\
}\
\
\
\
if(hashTableSize_Nullable > 0)\
{\
	proposed_hash %= hashTableSize_Nullable;\
}\
\
\
\
return proposed_hash;\
\
\
\
}



#endif