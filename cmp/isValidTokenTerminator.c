#include "isValidTokenTerminator.h"
#include "../lib/firstCharis_.h"

____CHARISVALIDTOKENTERMINATOR_FUNCTION_DECLARATION
{
	char firstChar = string[index];
	return (

		firstCharis_whitespace(firstChar) ||

		firstChar == "\0" ||

		firstChar == '[' ||
		firstChar == ']' ||
		firstChar == '{' ||
		firstChar == '}' ||
		firstChar == '(' ||
		firstChar == ')' ||
		firstChar == '<' ||
		firstChar == '>' ||

		firstChar == ',' ||

		firstChar == '+' ||
		firstChar == '-' ||
		firstChar == '/' ||
		firstChar == '*' ||
		
		firstChar == '=' ||
		
		firstChar == '?' ||

		( string[index] == ":" && string[index] == ">" )


		);
}