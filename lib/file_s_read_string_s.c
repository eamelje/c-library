//#define ____FILE_S_READ_STRING_S_DEBUG



#include "file_s_read_string_s.h"
#include "string_s_alloc.h"
#include "string_s_realloc.h"
#include "string_s_assignCharPtr.h"



#if defined(____FILE_S_READ_STRING_S_DEBUG)
#include <stdio.h>
#define ___DEBUG_PRINT_LINE(line) fprintf(stderr,"[DEBUG] :  file :  file_s_read_string_s.c .  line :  %i .  \n", line);
#endif



____FREAD_S_STRING_S_FUNCTION_DECLARATION{

stream->status = file_s_status_readFailure;


					#if defined(____FILE_S_READ_STRING_S_DEBUG)
					___DEBUG_PRINT_LINE(__LINE__)
					fprintf(stderr,"[DEBUG] :  file :  file_s_read_string_s.c .  buf->chars = %p .  buf->mem = %i .   \n", buf->chars, (int)buf->mem);
					#endif



if(buf->mem <= 0 || buf->chars == NULL)
{
	fprintf(stderr,"[DEBUG] :  Function file-s_read_string_s cannot write to buf.  buf.mem = %i ,  buf.chars = %p .  You must allocate more memory.  \n", (int)buf->mem, buf->chars);
}



if(read_len <= 0)
{
	return 0;
}



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
					#if defined(____FILE_S_READ_STRING_S_DEBUG)
					___DEBUG_PRINT_LINE(__LINE__)
					#endif
	temp = buf;
}


					#if defined(____FILE_S_READ_STRING_S_DEBUG)
					___DEBUG_PRINT_LINE(__LINE__)
					fprintf(stderr,"[DEBUG] :  file :  file_s_read_string_s.c .  temp->chars = %p .  temp->mem = %i .  \n",temp->chars,(int)temp->mem);
					#endif



/*std fread returns count of elements read*/
ui64_t fread_element_count = fread(temp->chars, sizeof(char), read_len, stream->stdFile);
					#if defined(____FILE_S_READ_STRING_S_DEBUG)
					___DEBUG_PRINT_LINE(__LINE__)
					fprintf(stderr,"[DEBUG] :  file :  file_s_read_string_s.c .  fread_element_count = %i .  \n",(int)fread_element_count);
					fprintf(stderr,"[DEBUG] :  file :  file_s_read_string_s.c .  stdio fread assigned the following value to the buffer :  \"%s\" .  \n", temp->chars);
					#endif



*temp = string_s_assignCharPtr(temp->chars);
					#if defined(____FILE_S_READ_STRING_S_DEBUG)
					___DEBUG_PRINT_LINE(__LINE__)
					fprintf(stderr,"[DEBUG] :  file :  file_s_read_string_s.c .  temp->chars = \"%s\" .  temp->len = %i .  temp->mem = %i .  \n", temp->chars, (int)temp->len, (int)temp->mem);
					#endif




if(mode == fread_s_string_s_mode_append)
{
	string_s_cat (buf, *temp, 0);
	string_s_free (temp);
	free(temp);/*DO NOT FREE IF MODE == OVERWRITE, BECAUSE THEN BUF PTR == TEMP PTR*/
}
					#if defined(____FILE_S_READ_STRING_S_DEBUG)
					___DEBUG_PRINT_LINE(__LINE__)
					#endif



if(fread_element_count < (ui64_t)(read_len*0.95 - 64) )// - realloc if wasting a lot of excess memory
{
						#if defined(____FILE_S_READ_STRING_S_DEBUG)
					___DEBUG_PRINT_LINE(__LINE__)
					#endif
	string_s_realloc(*buf, buf->len + 1, buf);
						#if defined(____FILE_S_READ_STRING_S_DEBUG)
					___DEBUG_PRINT_LINE(__LINE__)
					#endif
}



					#if defined(____FILE_S_READ_STRING_S_DEBUG)
					___DEBUG_PRINT_LINE(__LINE__)
					#endif



stream->status = file_s_status_readSuccess;



return fread_element_count;



}