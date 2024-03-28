#if !defined(____HEADER_GUARD_linked_list_alloc_h)
#define ____HEADER_GUARD_linked_list_alloc_h



#define ____FUNC_DECL_linked_list_alloc \
void \
linked_list_alloc\
(\
linked_list_t *anyBlock,/*any part of list*/\
ui32_t elementSize,
ui32_t elementCount
)



____FUNC_DECL_linked_list_alloc;



#define ____FUNC_DECL_linked_list_free \
void \
linked_list_free\
(\
linked_list_t *blockToFree\
)



____FUNC_DECL_linked_list_free;



#define ____FUNC_DECL_linked_list_freeLastBlock \
void \
linked_list_freeLastBlock\
(\
linked_list_t *anyBlock_EXCEPT_LAST\
)



____FUNC_DECL_linked_list_freeLastBlock;




#endif