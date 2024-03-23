# Defining variables, functions, and more  

- overview
    - syntax : ``def <defType> <name> = <data>``  
- examples
    - types
        - syntax : ``def type <name> = <type>``  
        - example 1 :  
            - ? : ``def type new = old;``  
            - c : ``typedef old new;``  
        - example 2 :  
            - ? : ``def type string = struct { chars = ui8ptr; ui32 len, mem; };``  
            - c : ``typedef struct {char *chars; uint32_t len, mem;} string;``  
        - example 3 :  
            - ? : ``def type string_len_type = ui32;``  
            - c : ``typedef uint32_t string_len_type;``  
    - variables  
        - syntax : ``def var <name> = <optional:attributes> <optional:type> <optional:value>``
        - example :  
            - ? : ``def var a = ui32 0;``  
                - type inference by assignment should be possible.  
	        - c : ``uint32_t a = 0;``  
    - functions  
        - syntax : ``def func <name> = <optional:attributes> <type> <optional:args> <body>``  
        - example :  
            - ? : ``def func sum = [[inline, static]] ui32 (ui16 a, ui16 b) {return a + b;}``  
	        - c : ``__attribute__((__always_inline__)) static uint32_t sum(uint16_t a, uint16_t b){return a + b;}``  
    - macros  
        - example :  
            - ? : ``def macro c = (a, b) {a + b}``  
            - c : ``#define c(a, b) a + b``  

# Directives  
- concatenating tokens  
    - syntax : ``#cat(comma separated values)``  
    - example :  
	    - ? :  ``#cat(a, b, c, d)``  
        - c : ``a ## b ## c ## d``  
- stringizing tokens  
    - syntax : ``#str(token)``  
    - example :  
        - ? :  ``#str(a)``  
            - not the same as #cat(",a,"), because that does not take into account escaped characters, like backslash, newline, and quotation marks.  
        - c : ``#a``  
- expanding a macro fully : ``a``  
- expanding a macro a specific number of steps : ``#exp(a, 1)``  
    - 2nd arg of exp macro directive is depth, and is optional.  
- using the macro's name instead of what its value : ``#nam(a)``  
- conditional code inclusion  
    - syntax :  
        - ``#if (<condition>) {<body>}``  
	    - ``#else {<body>}``  
	    - ``#else if (<condition>) {<body>}``  
	    - ``#isdef(<definedToken>)``  
	        - definedToken = anything defined using the def keyword  
- calling functions at compile time : ``#cal(<funcName>(<optional:funcArgs>))``  
- using a variable as code : ``#vtc(<var or funcCall)``  
- text and number manipulation at compile time  
    - can be done through function calls :  
        - truncate  
        - round up  
        - round down  
        - round  
        - floor  
        - ceiling  
    - can not be done through function calls  
        - ...  
- #warn : display a warning in stderr  
- #error : display an error in stderr and pause or exit application  
- #include : substitute the #include directive for the contents of the specified file  
- #uninclude : undo the definitions of an included file  
- #exclude : prevent a file from being included  
- #include_substitute : substitute one inclusion for another  
- ...  

# function attributes  
- inline  
- ...  

# variable attributes  
- ...  
- 
# types  
- common types  
    - unsigned integers  
        - ui8 : 8 bits  
        - ui16 : 16 bits  
        - ui32 : 32 bits  
        - ui64 : 64 bits  
    - signed integers  
        - i8 : 8 bits  
        - i16 : 16 bits  
        - i32 : 32 bits  
        - i64 : 64 bits  
    - floating point numbers  
    - enumeration  
    - structures  
    - unions  
    - typeless  
- uncommon types  
    - instruction pointer  
        - like labels in C, but can be reassigned to and from variables (no immediates)  
- inference  
    - ...  

# namespaces  
- ...  

# overloading functions  
- ...  
  
# function templates  