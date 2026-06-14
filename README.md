*This project has been created as part of the 42 curriculum by refernan.*

# ft_printf - @42sp

## Description
`ft_printf` is a project of the 42 curriculum. The goal is to create a library containing a reimplementation of the famous `printf` function from the standard C library (`<stdio.h>`). This project is designed to introduce the concept of variadic arguments in C, allowing a function to accept a variable number of arguments.

Building this library helped me solidify my knowledge of memory management, string formatting, and the C language logic, specifically regarding the use of `stdarg.h`.

## Instructions

### Compilation
To compile the library, simply run `make` in the root of the repository:

```bash
make
```

This will generate the `libftprintf.a` file.

### Makefile Targets
- `make` or `make all`: Compiles the source files and creates the library.
- `make clean`: Removes the object files (`.o`).
- `make fclean`: Removes the object files and the compiled library (`libftprintf.a`).
- `make re`: Recompiles the entire project (fclean + all).

### Usage
To use `ft_printf` in your own projects, include the header in your C files and link the library during compilation:

```c
#include "ft_printf.h"
```

Compile your project with:
```bash
cc your_file.c -L. -lftprintf -o your_program
```

## Detailed Description
The `ft_printf` function mimics the behavior of the original `printf` function and implements the following format specifiers:

- `%c`: Prints a single character.
- `%s`: Prints a string.
- `%p`: Prints a `void *` pointer argument in hexadecimal format.
- `%d`: Prints a decimal (base 10) number.
- `%i`: Prints an integer in base 10.
- `%u`: Prints an unsigned decimal (base 10) number.
- `%x`: Prints a number in hexadecimal (base 16) lowercase format.
- `%X`: Prints a number in hexadecimal (base 16) uppercase format.
- `%%`: Prints a literal percent sign.

### Internal Structure
The project is divided into several utility files for better organization:
- `ft_printf.c`: Contains the main logic, variadic argument handling, and the parser.
- `ft_str_utils.c`: Utilities for printing characters and strings.
- `ft_nbr_utils.c`: Utilities for handling integers and unsigned decimals.
- `ft_ptr_utils.c`: Utilities for pointer manipulation and hexadecimal printing.

## Resources
- [printf(3) - Linux man page](https://man7.org/linux/man-pages/man3/printf.3.html)
- [C library macro - va_arg](https://www.tutorialspoint.com/c_standard_library/c_macro_va_arg.htm)
- 42 School Norminette documentation.

### AI Usage
AI (Gemini) was used during this project for the following tasks:
- **Documentation:** Structuring and drafting this `README.md` to ensure it meets all the curriculum requirements while maintaining a clear and natural tone, mirroring the structure of previous projects.
- **Code Optimization Hints:** Occasional consultation on edge cases for specific conversions (like `%x` and `%p`) to ensure robust logic.