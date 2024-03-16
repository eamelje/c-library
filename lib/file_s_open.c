//#define __________FILE_S_OPEN_DEBUG
#define __________FILE_S_CLOSE_DEBUG


#include "file_s_open.h"



#if defined(__________FILE_S_OPEN_DEBUG) || defined(__________FILE_S_CLOSE_DEBUG)
#include <stdio.h>
#endif



#define __________STD_FCLOSE_SUCCESS 0



char_ptr_t file_s_open_mode_t_array[ ____file_s_open_mode_t_count ] = 
{
	[file_s_open_mode_read_binary] = "rb", 
	[file_s_open_mode_write_binary] = "wb"
};



____file_s_open_function_declaration{

	#if defined(__________FILE_S_OPEN_DEBUG)
	fprintf(stderr,"[DEBUG] :  file_s_open.c :  function file_s_open :  \n");
	//fprintf(stderr,"file_s_open_mode_read_binary == %s .  file_s_open_mode_write_binary == %s .  \n",file_s_open_mode_t_array[file_s_open_mode_read_binary],file_s_open_mode_t_array[file_s_open_mode_write_binary]);
	fprintf(stderr,"path.chars = \"%s\" .  mode = \"%s\" .  Line :  %i .  \n",path.chars,file_s_open_mode_t_array[mode],__LINE__);
	#endif

if((*file).isOpen)
{
fprintf(stderr,"[WARNING] :  please close the current file before opening a new one .  \n");
(*file).status = file_s_status_openFailure_alreadyOpen;
return EXIT_FAILURE;
}


(*file).stdFile = fopen (path.chars, file_s_open_mode_t_array[mode]);

	#if defined(__________FILE_S_OPEN_DEBUG)
	fprintf(stderr,"after std fopen, (*file).stdFile == %p .  \n",(*file).stdFile);
	#endif

if ( (*file).stdFile == NULL ) 
{
		#if defined(__________FILE_S_OPEN_DEBUG)
		fprintf(stderr,"(*file).stdFile == NULL => TRUE .  Line :  %i .  \n", __LINE__);
		#endif
	(*file).status = file_s_status_openFailure; 
	(*file).isOpen = false;
	return EXIT_FAILURE;
}
else
{
			#if defined(__________FILE_S_OPEN_DEBUG)
			fprintf(stderr,"(*file).stdFile == NULL => FALSE .  Line :  %i .  \n", __LINE__);
			#endif
	(*file).status = file_s_status_openSuccess;
	(*file).isOpen = true;
	return EXIT_SUCCESS;
}

}/*file_s_open*/



____file_s_close_function_declaration{

	#if defined(__________FILE_S_OPEN_DEBUG)
	fprintf(stderr,"before std fclose, (*file).stdFile == %p .  \n",(*file).stdFile);
	#endif

if((*file).stdFile == NULL)
{
			#if defined(__________FILE_S_OPEN_DEBUG)
			fprintf(stderr,"[DEBUG] :  file_s_open.c :  function file_s_close :  file could not be closed .  (*file).stdFile == NULL => TRUE .  \n");
			#endif

	goto _FAILURE;
}

if ( fclose ((*file).stdFile) == __________STD_FCLOSE_SUCCESS )
{
	(*file).status = file_s_status_closeSuccess;
	(*file).isOpen = false;
			#if defined(__________FILE_S_CLOSE_DEBUG)
			fprintf(stderr,"[DEBUG] :  file_s_close was successful .  \n");
			#endif
	return EXIT_SUCCESS;
}
else
{
	_FAILURE:
	(*file).status = file_s_status_closeFailure;
	return EXIT_FAILURE;
}
}/*file_s_close*/