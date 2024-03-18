#include "test.h"


#define file_func_test_file "../lib/file_func_test_file.txt"



/*list of functions with success status
* string_s_assignCharPtr, true
* string_s_equal, true
* string_s_free, true
* string_s_cat, true
* string_s_is_lower, true
* string_s_is_upper, true
* string_s_is_digit, true
* string_s_is_whitespace, true
* string_s_len, true
* file_s_open, ?
* file_s_close, ?
* fread_s_string_s, ?
* string_s_copy, ?
* string_s_realloc, ?
*/



____test_function_declaration{
printf ( "[DEBUG] :  PRINTING LINES AND STATUS\n\n");
string_s_t a, b, c, d;
file_s_t file_var;
bool bool_a;


bool placeholder_bool = false;
char_ptr_t placeholder_str = "";

#define PRINT_LINE_STATUS(condition_true,line__) \
if(!(condition_true)) \
{placeholder_str = "ERROR";\
} else { \
placeholder_str = "success";}\
fprintf(stderr, "[DEBUG] :  %i %s\n",line__,placeholder_str);

#define PRINT_LINE_TEST(line__) printf("[test] %llu\n",(unsigned long long)line__);

fprintf(stderr,"[DEBUG] :  functions: string_s_assignCharPtr, string_s_equal, string_s_free\n");

a = string_s_assignCharPtr ( "Hello, World!" );
b = string_s_assignCharPtr ( "1234Hello, World!" );
PRINT_LINE_STATUS(string_s_equal ( a, b, 0, 4, 0 ),__LINE__)/*should be true*/
PRINT_LINE_STATUS(!string_s_equal ( a, b, 0, 3, 0 ),__LINE__)/*should be false*/
string_s_free(&a);
string_s_free(&b);


a = string_s_assignCharPtr ( "hi!" );
b = string_s_assignCharPtr ( "HI!" );
PRINT_LINE_STATUS(!string_s_equal ( a, b, 0, 0, 0 ),__LINE__)/*should be false*/
string_s_free(&a);
string_s_free(&b);


fprintf (stderr, "[DEBUG] :  functions: string_s_cat\n" );

a = string_s_assignCharPtr ( "asd" );
b = string_s_assignCharPtr ( "qwe" );
string_s_cat(&a,b,0);
string_s_free(&b);
c = string_s_assignCharPtr("asdqwe");
		//fprintf(stderr, "[DEBUG] a :  %s    c :  %s\n",a.chars,c.chars);//temp
PRINT_LINE_STATUS(string_s_equal ( a, c, 0, 0, 0 ),__LINE__)/*should be true*/
string_s_free(&a);
string_s_free(&c);


fprintf (stderr, "[DEBUG] :  functions: string_s_is_lower\n" );
a = string_s_assignCharPtr ( "asd" );
b = string_s_assignCharPtr ( "qWe" );
c = string_s_assignCharPtr ( "z!a" );
PRINT_LINE_STATUS ( string_s_is_lower ( a ), __LINE__ )/*should be true*/
PRINT_LINE_STATUS ( !string_s_is_lower ( b ), __LINE__ )/*should be false*/
PRINT_LINE_STATUS ( !string_s_is_lower ( c ), __LINE__ )/*should be false*/
string_s_free ( &a );
string_s_free ( &b );
string_s_free ( &c );

fprintf (stderr, "[DEBUG] :  functions: string_s_is_upper\n" );
a = string_s_assignCharPtr ( "WER" );
b = string_s_assignCharPtr ( "TdS" );
c = string_s_assignCharPtr ( "P%G" );
PRINT_LINE_STATUS ( string_s_is_upper ( a ), __LINE__ )/*should be true*/
PRINT_LINE_STATUS ( !string_s_is_upper ( b ), __LINE__ )/*should be false*/
PRINT_LINE_STATUS ( !string_s_is_upper ( c ), __LINE__ )/*should be false*/
string_s_free ( &a );
string_s_free ( &b );
string_s_free ( &c );


fprintf (stderr, "[DEBUG] :  functions: string_s_is_digit\n" );
a = string_s_assignCharPtr ( "1234567890" );
b = string_s_assignCharPtr ( "4e5" );
c = string_s_assignCharPtr ( "0x40" );
PRINT_LINE_STATUS ( string_s_is_digit ( a ), __LINE__ )/*should be true*/
PRINT_LINE_STATUS ( !string_s_is_digit ( b ), __LINE__ )/*should be false*/
PRINT_LINE_STATUS ( !string_s_is_digit ( c ), __LINE__ )/*should be false*/
string_s_free ( &a );
string_s_free ( &b );
string_s_free ( &c );


fprintf (stderr, "[DEBUG] :  functions: string_s_is_whitespace\n" );
a = string_s_assignCharPtr ( "\t" );
b = string_s_assignCharPtr ( " " );
c = string_s_assignCharPtr ( "\n" );
d = string_s_assignCharPtr ( "hello world!" );
PRINT_LINE_STATUS ( string_s_is_whitespace ( a ), __LINE__ )/*should be true*/
PRINT_LINE_STATUS ( string_s_is_whitespace ( b ), __LINE__ )/*should be true*/
PRINT_LINE_STATUS ( string_s_is_whitespace ( c ), __LINE__ )/*should be true*/
PRINT_LINE_STATUS ( !string_s_is_whitespace ( d ), __LINE__ )/*should be false*/
string_s_free ( &a );
string_s_free ( &b );
string_s_free ( &c );
string_s_free ( &d );


fprintf (stderr, "[DEBUG] :  functions: string_s_len\n" );
a = string_s_assignCharPtr ( "a" );
b = string_s_assignCharPtr ( "" );
c = string_s_assignCharPtr ( "1bcdef7" );
d = string_s_assignCharPtr ( "\t\t \n" );
PRINT_LINE_STATUS ( (string_s_len ( a ) == 1), __LINE__ )/*should be true*/
PRINT_LINE_STATUS ( (string_s_len ( b ) == 0), __LINE__ )/*should be true*/
PRINT_LINE_STATUS ( (string_s_len ( c ) == 7), __LINE__ )/*should be true*/
PRINT_LINE_STATUS ( (string_s_len ( d ) == 4), __LINE__ )/*should be true*/
string_s_free ( &a );
string_s_free ( &b );
string_s_free ( &c );
string_s_free ( &d );


printf ( "[DEBUG] :  functions: file_s_open, file_s_close\n" );

fprintf(stderr, "[DEBUG] :  file_func_test_file == \"%s\" .  in file \"test.c\" at line %i\n",file_func_test_file,__LINE__);
if(file_exists(file_func_test_file) == false){fprintf(stderr,"[DEBUG] :  file \" %s \" does not exist .  \n",file_func_test_file);}
a = string_s_assignCharPtr(file_func_test_file);
bool_a = file_s_open(&file_var, a, file_s_open_mode_read_binary);
PRINT_LINE_STATUS ( file_var.stdFile != NULL, __LINE__ )/*should be false*/
PRINT_LINE_STATUS ( bool_a == EXIT_SUCCESS, __LINE__ )/*should be true*/
PRINT_LINE_STATUS ( file_var.isOpen, __LINE__ )/*should be true*/
PRINT_LINE_STATUS ( file_var.status == file_s_status_openSuccess, __LINE__ )/*should be true*/

file_s_close(&file_var);
PRINT_LINE_STATUS ( !file_var.isOpen, __LINE__ )/*should be false*/
string_s_free ( &a );


printf ( "[DEBUG] :  functions: fread_s_string_s\n" );
a = string_s_assignCharPtr(file_func_test_file);
	PRINT_LINE_TEST(__LINE__)
file_s_open(&file_var, a, file_s_open_mode_read_binary);
	PRINT_LINE_TEST(__LINE__)
ui32_t read_len_expected = 32;
string_s_alloc(&b, read_len_expected);
	PRINT_LINE_TEST(__LINE__)
ui32_t read_len_actual = fread_s_string_s(&b, fread_s_string_s_mode_overwrite, read_len_expected, file_var);
fprintf(stderr,"[DEBUG] :  read_len_actual :  %i .  read_len_expected :  %i .  \n", (int)read_len_expected, (int)read_len_actual);
PRINT_LINE_STATUS ( read_len_expected == read_len_actual, __LINE__ )/*should be true*/
printf("\n[DEBUG] :  DONE\n");


return true;

}/*test*/
