#if !defined(____HEADER_GUARD_linked_list_type_h)
#define ____HEADER_GUARD_linked_list_type_h



typedef LINKED_LIST_T
{
struct linked_list_t *nextPtr;
void *dataPtr;
ui16_t 
  dataPtr_elementCount, 
  dataPtr_startIndex;
} 
linked_list_t;



#endif