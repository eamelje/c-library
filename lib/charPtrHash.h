#if !defined(____HEADER_GUARD_charPtrHash_h)
#define ____HEADER_GUARD_charPtrHash_h



#define ____FUNCTION_DECLARATION_TEMPLATE_charPtrHash(size_) \
ui ## size_ ## _t \
charPtrHash ## size_\
(\
char *charPtr,\
ui32_t ptrSize,\
ui32_t hashTableSize_Nullable\
)



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
if(indexMax > 250){index_step_size = 10;}\
if(indexMax > 100){index_step_size = 5;}\
else if(indexMax > 25){index_step_size = 3;}\
else {index_step_size = 1;}\
if( (hashTableSize_Nullable > 0) && (ptrSize & 1) )/* is odd */\
{\
proposed_hash += (_ui ## size_ ## _max_value / 2);\
}\
_LABEL_A:\
proposed_hash += (index % 17)\
proposed_hash += charPtr[index];\
if(index <= indexMax)\
{\
	index += index_step_size;\
	goto _LABEL_A;\
}\
if(hashTableSize_Nullable > 0)\
{\
	proposed_hash %= hashTableSize_Nullable;\
}\
return proposed_hash;\
}



#endif