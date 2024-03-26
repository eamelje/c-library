typedef LINKED_LIST_T
{
struct linked_list_t *nextPtr;
void *dataPtr;
ui16_t 
  dataPtr_elementCount, 
  dataPtr_startIndex;
} 
linked_list_t;



#define ____FUNC_DECL_linked_list_alloc \
void \
linked_list_alloc\
(\
linked_list_t *anyBlock,/*any part of list*/\
ui32_t elementSize,
ui32_t elementCount
)



____FUNC_DECL_linked_list_alloc
{



linked_list_t *lastBlock = anyBlock->nextPtr, newBlock;



if(lastBlock->nextPtr !=  NULL)/*is not last block yet*/
{
lastBlock = lastBlock->nextPtr;
goto _FIND_LAST_PTR;
}



newBlock.dataPtr = malloc(elementSize * elementCount);
newBlock.dataPtr_elementCount = elementCount;
newBlock.dataPtr_startIndex = lastBlock->dataPtr_startIndex + lastBlock->dataPtr_elementCount;



lastBlock->nextPtr = &newBlock;



}