#include "token_core.h"
#include "tryGetToken_immediateString.h"
#include "../lib/exitStatus_type.h"
#include <stdio.h>



____TRYGETTOKEN_IMMEDIATESTRING_FUNCTION_DECLARATION
{



exitStatus_extra_t r;


if(sourceCode[sourceCodeIndex] != TOKEN_STRINGsTART)
{
	return exitStatus_failure;
}


string_s_t tokenValue;
tokenValue.len = 0;
tokenValue.chars = NULL;

ui32_t 
	tokenValueIndex = 0,
	tokenValueIndexMax,
	sourceCodeIndex_temp = *sourceCodeIndex;

exitStatus_t shouldEscapeCurrentChar = false;



if(true) {

	(*sourceCodeIndex)++;
	sourceCodeIndex_temp = *sourceCodeIndex;



_LABEL_IMMEDIATESTRING_VALUECALC:

	if(shouldEscapeCurrentChar)
	{
		if(sourceCode[sourceCodeIndex_temp] == TOKEN_ESCAPED_CHAR_NEWlINE || 
		sourceCode[sourceCodeIndex_temp] == TOKEN_ESCAPED_CHAR_ESCAPEcHAR || 
		sourceCode[sourceCodeIndex_temp] == TOKEN_ESCAPED_CHAR_TAB || 
		sourceCode[sourceCodeIndex_temp] == TOKEN_ESCAPED_CHAR_NULL || 
		sourceCode[sourceCodeIndex_temp] == TOKEN_ESCAPED_CHAR_STRINGeND 
		)
		{
			shouldEscapeCurrentChar = false;
			sourceCodeIndex_temp++;
			tokenValue.len++;
			goto _LABEL_A;
		}
		else
		{
			fprintf(stderr,"[ERROR] :  You cannot escape the character '%c' \n", sourceCode[sourceCodeIndex_temp])/*error and exit*/
			r.status = exitStatus_failure;
			r.shouldExitApplication = true;
			return r;
		} 
	}



	if(sourceCode[sourceCodeIndex_temp] == TOKEN_ESCAPEcHAR)
	{
		shouldEscapeCurrentChar = true;
		sourceCodeIndex_temp++;
		goto _LABEL_IMMEDIATESTRING_VALUECALC;
	}



	if(sourceCode[sourceCodeIndex_temp] == TOKEN_STRINGeND)
	{
		goto _LABEL_STRING_VALUECALC_FINISHED;
	}



	if(true)
	{
		sourceCodeIndex_temp++;
		tokenValue.len++;
		goto _LABEL_IMMEDIATESTRING_VALUECALC;
	}



}



_LABEL_STRING_VALUECALC_FINISHED:

shouldEscapeCurrentChar = false;
sourceCodeIndex_temp = *sourceCodeIndex;
tokenValueIndexMax = tokenValue.len - 1;

string_s_alloc(&tokenValue, tokenValue.len + 1);



/*assign every char, then null terminate*/

_LABEL_IMMEDIATESTRING_ASSIGN:

if(tokenValueIndex <= tokenValueIndexMax)
{

	if(shouldEscapeCurrentChar)
	{



		shouldEscapeCurrentChar = false;



		if(sourceCode[sourceCodeIndex_temp] == TOKEN_ESCAPED_CHAR_ESCAPEcHAR)
		{
			tokenValue.chars[tokenValueIndex] = TOKEN_ESCAPEcHAR;
		} else

		if(sourceCode[sourceCodeIndex_temp] == TOKEN_ESCAPED_CHAR_STRINGeND)
		{
			tokenValue.chars[tokenValueIndex] = TOKEN_STRINGeND;
		} else

		if(sourceCode[sourceCodeIndex_temp] == TOKEN_ESCAPED_CHAR_NEWlINE)
		{
			tokenValue.chars[tokenValueIndex] = '\n';
		} else

		if(sourceCode[sourceCodeIndex_temp] == TOKEN_ESCAPED_CHAR_TAB)
		{
			tokenValue.chars[tokenValueIndex] = '\t';
		} else

		if(sourceCode[sourceCodeIndex_temp] == TOKEN_ESCAPED_CHAR_NULL)
		{
			tokenValue.chars[tokenValueIndex] = '\0';
		}



		tokenValueIndex++;
		sourceCodeIndex_temp++;
		goto _LABEL_IMMEDIATESTRING_ASSIGN;



	} else



	if(sourceCode[sourceCodeIndex_temp] == TOKEN_ESCAPEcHAR)
	{
		shouldEscapeCurrentChar = true;
		sourceCodeIndex_temp++;
		goto _LABEL_IMMEDIATESTRING_ASSIGN;
	} else



	tokenValue.chars[tokenValueIndex] = sourceCode[sourceCodeIndex_temp];
	tokenValueIndex++;
	sourceCodeIndex_temp++;
	goto _LABEL_IMMEDIATESTRING_ASSIGN;



} else



*sourceCodeIndex = sourceCodeIndex_temp + 2;/*+1 cause string end char ('"') and +1 toget to char AFTER that*/
tokenValue.chars[tokenValueIndex] = '\0';



((tokenStack->ptr)[(tokenStack->index)]).value = tokenValue;
((tokenStack->ptr)[(tokenStack->index)]).type = tt_immediateString;



r.status = exitStatus_success;
r.shouldExitApplcation = false;
return r;



}