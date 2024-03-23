/* maybe don't check if token sequence is valid during tokenisation, since that's potentially a lot of time wasted.*/


#include "compiler_tokenise.h"
#include "token_type.h"
#include "token_core.h"
#include "../lib/char_is_.h"
#include "../lib/exit_status_type.h"
#include <malloc.h>

#define TOKENsTACK_GROWTH_SIZE 128

#define srcChar ((sourceCode.chars)[sourceCodeIndex])

____COMPILER_TOKENISE_FUNCTION_DECLARATION
{


ui32_t stackIndexMax = (tokenStack->mem) - 1;
void *tempReallocPtr = NULL;
ui32_t sourceCodeIndex = 0;




_LABEL_TRYGETTOKEN:

/* alloc */
if((tokenStack->index) == stackIndexMax )
{
	tokenStack->mem += TOKENsTACK_GROWTH_SIZE;
	tempReallocPtr = realloc((tokenStack->ptr), (tokenStack->mem));
	stackIndexMax = (tokenStack->mem) - 1;
}



_LABEL_SKIP_EXTRA_WHITESPACE:
if( char_is_whitespace(srcChar) )
{
	sourceCodeIndex++;
	goto _LABEL_SKIP_EXTRA_WHITESPACE;
}

/* defined names */
if( compiler_tryGetToken_definedMacro(sourceCode, &sourceCodeIndex, tokenStack) == exitStatus_success )
{
	goto _LABEL_TRYGETTOKEN;
}

if( compiler_tryGetToken_definedVariable(sourceCode, &sourceCodeIndex, tokenStack) == exitStatus_success )
{
	goto _LABEL_TRYGETTOKEN;
}

if( compiler_tryGetToken_definedType(sourceCode, &sourceCodeIndex, tokenStack) == exitStatus_success )
{
	goto _LABEL_TRYGETTOKEN;
}

if( compiler_tryGetToken_definedFunction(sourceCode, &sourceCodeIndex, tokenStack) == exitStatus_success )
{
	goto _LABEL_TRYGETTOKEN;
}



/* keywords */

if( compiler_tryGetToken_keyword_call(sourceCode, &sourceCodeIndex, tokenStack) == exitStatus_success )
{
	goto _LABEL_TRYGETTOKEN;
}

if( compiler_tryGetToken_keyword_define(sourceCode, &sourceCodeIndex, tokenStack) == exitStatus_success )
{
	goto _LABEL_TRYGETTOKEN;
}
if( compiler_tryGetToken_keyword_mathMultiplication(sourceCode, &sourceCodeIndex, tokenStack) == exitStatus_success )
{
	goto _LABEL_TRYGETTOKEN;
}

if( compiler_tryGetToken_keyword_mathAddition(sourceCode, &sourceCodeIndex, tokenStack) == exitStatus_success )
{
	goto _LABEL_TRYGETTOKEN;
}

if( compiler_tryGetToken_keyword_mathSubtraction(sourceCode, &sourceCodeIndex, tokenStack) == exitStatus_success )
{
	goto _LABEL_TRYGETTOKEN;
}

if( compiler_tryGetToken_keyword_mathDivision(sourceCode, &sourceCodeIndex, tokenStack) == exitStatus_success )
{
	goto _LABEL_TRYGETTOKEN;
}

if( compiler_tryGetToken_keyword_logicInversion(sourceCode, &sourceCodeIndex, tokenStack) == exitStatus_success )
{
	goto _LABEL_TRYGETTOKEN;
}

if( compiler_tryGetToken_keyword_logicGreaterEqual(sourceCode, &sourceCodeIndex, tokenStack) == exitStatus_success )
{
	goto _LABEL_TRYGETTOKEN;
}

if( compiler_tryGetToken_keyword_logicGreater(sourceCode, &sourceCodeIndex, tokenStack) == exitStatus_success )
{
	goto _LABEL_TRYGETTOKEN;
}

if( compiler_tryGetToken_keyword_logicEqual(sourceCode, &sourceCodeIndex, tokenStack) == exitStatus_success )
{
	goto _LABEL_TRYGETTOKEN;
}

if( compiler_tryGetToken_keyword_logicLessEqual(sourceCode, &sourceCodeIndex, tokenStack) == exitStatus_success )
{
	goto _LABEL_TRYGETTOKEN;
}

if( compiler_tryGetToken_keyword_logicLess(sourceCode, &sourceCodeIndex, tokenStack) == exitStatus_success )
{
	goto _LABEL_TRYGETTOKEN;
}

if( compiler_tryGetToken_keyword_logicOr(sourceCode, &sourceCodeIndex, tokenStack) == exitStatus_success )
{
	goto _LABEL_TRYGETTOKEN;
}

if( compiler_tryGetToken_keyword_logicAnd(sourceCode, &sourceCodeIndex, tokenStack) == exitStatus_success )
{
	goto _LABEL_TRYGETTOKEN;
}

if( compiler_tryGetToken_keyword_logicXor(sourceCode, &sourceCodeIndex, tokenStack) == exitStatus_success )
{
	goto _LABEL_TRYGETTOKEN;
}

if( compiler_tryGetToken_keyword_bitOnesComplement(sourceCode, &sourceCodeIndex, tokenStack) == exitStatus_success )
{
	goto _LABEL_TRYGETTOKEN;
}

if( compiler_tryGetToken_keyword_bitTwosComplement(sourceCode, &sourceCodeIndex, tokenStack) == exitStatus_success )
{
	goto _LABEL_TRYGETTOKEN;
}

if( compiler_tryGetToken_keyword_bitShiftLeft(sourceCode, &sourceCodeIndex, tokenStack) == exitStatus_success )
{
	goto _LABEL_TRYGETTOKEN;
}

if( compiler_tryGetToken_keyword_bitShiftRight(sourceCode, &sourceCodeIndex, tokenStack) == exitStatus_success )
{
	goto _LABEL_TRYGETTOKEN;
}

if( compiler_tryGetToken_keyword_bitOr(sourceCode, &sourceCodeIndex, tokenStack) == exitStatus_success )
{
	goto _LABEL_TRYGETTOKEN;
}

if( compiler_tryGetToken_keyword_bitAnd(sourceCode, &sourceCodeIndex, tokenStack) == exitStatus_success )
{
	goto _LABEL_TRYGETTOKEN;
}

if( compiler_tryGetToken_keyword_bitXor(sourceCode, &sourceCodeIndex, tokenStack) == exitStatus_success )
{
	goto _LABEL_TRYGETTOKEN;
}






/* defining names*/
/*THESE PROBABLY SHOULDN'T BE CALLED LIKE THIS< THEY SHOULD PROBABLY ONLY BE CALLED WHEN A DEFINITION IS ONGOING*/
if( compiler_tryGetToken_definitiontype_function(sourceCode, &sourceCodeIndex, tokenStack) == exitStatus_success )
{
	goto _LABEL_TRYGETTOKEN;
}

if( compiler_tryGetToken_definitiontype_variable(sourceCode, &sourceCodeIndex, tokenStack) == exitStatus_success )
{
	goto _LABEL_TRYGETTOKEN;
}

if( compiler_tryGetToken_definitionfield_name(sourceCode, &sourceCodeIndex, tokenStack) == exitStatus_success )
{
	/*LOOK FOR EITHER:
	VALID NAME, RIGHT ASSIGNMENT, NAME FIELD
	OR
	NAME FIELD, LEFT ASSIGNMENT, VALID NAME
	FOR EXAMPLE
	name :< functionName1234
	OR
	functionName1234 >: name
	*/
	goto _LABEL_TRYGETTOKEN;
}




/* immediate values */

if( compiler_tryGetToken_immediateString( sourceCode, &sourceCodeIndex, tokenStack ) == exitStatus_success )
{
	goto LABEL_TRYGETTOKEN;
}

if( compiler_tryGetToken_immediateInt(sourceCode, &sourceCodeIndex, tokenStack) == exitStatus_success )
{
	goto _LABEL_TRYGETTOKEN;
}

if( compiler_tryGetToken_immediateFloat(sourceCode, &sourceCodeIndex, tokenStack) == exitStatus_success )
{
	goto _LABEL_TRYGETTOKEN;
}




_LABEL_CHECK_IF_VALID_TOKEN_SEQUENCE:
/* list all invalid token sequences */
if(invalidTokenSequenceCount > 0)
{
	exit(exitStatus_failure);
}

}/*compiler_tokenise*/