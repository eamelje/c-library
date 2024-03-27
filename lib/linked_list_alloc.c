#include "linked_list_alloc.h"
#include "exit_status_type.h"



____FUNC_DECL_linked_list_alloc
{



linked_list_t *lastBlock = anyBlock->nextPtr, newBlock;



if(lastBlock->nextPtr !=  NULL)/*if is not last block yet*/
{
lastBlock = lastBlock->nextPtr;/*climb block ladder*/
goto _FIND_LAST_PTR;
}



/*create new block*/
newBlock.dataPtr = malloc(elementSize * elementCount);
newBlock.dataPtr_elementCount = elementCount;
newBlock.dataPtr_startIndex = lastBlock->dataPtr_startIndex + lastBlock->dataPtr_elementCount;



/*assign new block ptr to lastBlock.nextPtr*/
lastBlock->nextPtr = &newBlock;



}



____FUNC_DECL_linked_list_free
{



if(blockToFree != NULL)
{
	
	
	if(blockToFree->dataPtr != NULL)
	{
		free(blockToFree->dataPtr);
	}


	free(blockToFree);


}


return;



}



____FUNC_DECL_linked_list_freeLastBlock
{



if(anyBlock_EXCEPT_LAST->nextPtr == NULL)
{
	exit(exitStatus_failure);
}


linked_list_t *ptr1 = anyBlock_EXCEPT_LAST, ptr2;


_FIND_LAST_BLOCK:
if(ptr1->nextPtr != NULL)
{
	ptr2 = ptr1;
	ptr1 = ptr1->nextPtr;
	goto _FIND_LAST_BLOCK;
}


ptr2->nextPtr = NULL;
linked_list_free(ptr1);
return;




}