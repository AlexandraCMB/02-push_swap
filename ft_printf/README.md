*This project has been created as part of the 42 curriculum by abrunjes*

# ft_printf
[Description](#description)<br >
[Topics](#topics)
- [Makefile](#makefile)
- [Variadic Functions](#variadicfunctions)

 [Pseudocode](#pseudocode)<br >
[Instructions](#instructions)<br >
[Resources](#resources)<br >

## Description

A 42 project in which I replicated the basic behaviours of the `printf` function limited to just the conversion specifiers detailed below. `ft_print` writes the formatted string  to stdout and it's return value is the number of characters written. 

The following conversions have been implemented:

- <span style="color:magenta">%c</span> - prints a single character.
- <span style="color:magenta">%s</span> - prints a string.
-  <span style="color:magenta">%p</span> - prints a (void *) pointer argument in hexadecimal format.
-  <span style="color:magenta">%d</span> - prints a decimal (base 10) integer.
-  <span style="color:magenta">%i</span> - prints an integer in base 10. (*subtle difference from %d - in this proj
ect it behaves the same*)
-  <span style="color:magenta">%u</span> - prints an unsigned decimal integer
-  <span style="color:magenta">%x</span> - prints an integer in lowercase hexadecimal.
-  <span style="color:magenta">%X</span> - prints and integer in uppercase hexadecimal.
-  <span style="color:magenta">%c</span> - prints a percent sign.
<br >

## Topics
 ### Makefile
`ft_printf` and it's assocation utility functions are compiled into a static library `libftprintf.a` by my Makefile. The Makefile handles compilation, archiving, cleaning and rebuilding. It has an additional `test` target that builds and runs a test execulatable with a `main.c` to be provided by the evaluator.
### Variadic Functions
`ft_printf` is a variadic function, meaning it is a function that handles a variable number of arguments. The `...` in the prototype below indicates this.
```
int ft_printf(const char *format, ...);
```
The variable arguments in the function are managed using the `<stdarg.h>` header library. This creates a  `va_list` type which stores a variable often called `ap`. The `...` arguments in the function are then managed by the following macros:

- `va_start(ap, last_fixed_arg)` initialises `ap` to point to the first variable argument (i.e the first argument after `format`)
- `va_arg(ap, type)` retrieves the current argument processing it as whatever type is declared. It then points to the next argument in the list.
- `va_end(ap)` must always be called in a function after a `va_start` has been called. It is the cleaning up process. 
## Pseudocode

The function traverses along the `char *format` string writing each character to `stdout` and keeping tracking of the total characters written. Once a `%` sign is found the next character is examined as a format specifier. At this point a separate 'ft_specifier' funtion is called. This function reads the argument type and calls the approroptiate function that processes the argument to be printed which all in turn count the total number of characters printed.

### ft_printf()
- Initialize `va_list` (the '`...`' arguments) using `va_start`.

- Initialize `total_length` to `0`.

- Loop through each character of the format string:
	- **If** character is `%`:
		- Advance to the next character (the specifier).
		- Call `ft_specifier()`.
		- Add the return value of that function to total_length.

	- **Else**:
		- Write the character to stdout.
		- Increment `total_length`.
- Clean up `va_list` using `va_end`.
- Return `total_length`.
### ft_specifier()
- Cycles through `if else` statements until specifier matching input is found.
- Once found it calls the argument in the list which is processed by the appropritate function.
- Each function will write the arguemtn as required and return the length of argument written.
## Instructions
For testing, compile as below in terminal with *your* `main.c` included in the project directory:
```
cc -Wall -Wextra -Werror ft*.c main.c -o test.out && ./test.out
```
Alternatively, you can make use of the Makefile and run:
``` 
make test && ./test.out
```

## Resources
- man 3 printf <br>
- man 3 va_arg <br>
- Peers<br>
- [Wiki - Variadic Functions](https://en.wikipedia.org/wiki/Variadic_function)<br>
- [Wiki - printf](https://en.wikipedia.org/wiki/Printf)

<span style="color:red">AI usage</span>  for README.md formatting and help understanding man pages.
## 


[Return to top](#top)

