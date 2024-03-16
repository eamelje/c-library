#include "file_s_read_string_s.h"
#include "string_s_alloc.h"
#include "string_s_realloc.h"



____FREAD_S_STRING_S_FUNCTION_DECLARATION{

string_s_t *temp;

if(mode == fread_s_string_s_mode_append)
{
	temp = malloc(1 * sizeof(string_s_t));
	*temp = (string_s_t){
	.chars = NULL, 
	#if defined(____STRING_S_T_USE_MEMORY_FIELD)
	.mem = 0, 
	#endif
	.len = 0, .index = 0};
	string_s_alloc (temp, read_len + 1);
}
else if(mode == fread_s_string_s_mode_overwrite)
{
	temp = buf;
}

/*std fread returns count of elements read*/
ui64_t fread_element_count = fread(temp, sizeof(char), read_len, stream.stdFile);

if(mode == fread_s_string_s_mode_append)
{
	string_s_cat (buf, *temp, 0);
	string_s_free (temp);
	free(temp);/*DO NOT FREE IF MODE == OVERWRITE, BECAUSE THEN BUF PTR == TEMP PTR*/
}

if(fread_element_count < (ui64_t)(read_len*0.95 - 64) )// - realloc if wasting a lot of excess memory
{
	string_s_realloc(*buf, (*buf).len + 1, buf);
}

return fread_element_count;
}