*This project has been created as part of the 42 curriculum by refernan.*

# ft_printf - @42sp

## Description
The goal of this project is pretty straightforward: to recode the famous `printf()` function from the standard C library (`<stdio.h>`). This project serves as a structured introduction to variadic functions in C, allowing a function to accept a variable number of arguments through `stdarg.h`.

The implementation focuses on mimicking the original behavior of the system's `printf` concerning output format and character counting, while emphasizing structured, error-resilient, and highly extensible code without relying on complex buffer management. 

Building this library helped me solidify my knowledge of memory management, string formatting, and the C language logic.

## Instructions

### Compilation
To compile the library, simply run `make` in the root of the repository:

```bash
make
```

This will generate the `libftprintf.a` file at the root of the repository.

### Makefile Targets
- `make` or `make all`: Compiles the source files and creates the static library `libftprintf.a`.
- `make clean`: Removes the local object files (`.o`).
- `make fclean`: Removes the object files and the compiled library file.
- `make re`: Recompiles the entire project from scratch (fclean + all) without performing unnecessary relinking.

### Usage
To use `ft_printf` in your own C projects, include the header file and link the compiled library during compilation:

```c
#include "ft_printf.h"
```

Compile your project linking the static library:
```bash
cc your_file.c libftprintf.a -o your_program
```

## Detailed Description
The project is built on top of a modular and linear architecture. The core logic is driven by a main parser that iterates through the format string and delegates specialized printing responsibilities to specific utility modules:

### Supported Conversions
The library fully handles the following mandatory specifiers:

- `%c`: Prints a single character.
- `%s`: Prints a string (handles `NULL` gracefully by outputting `(null)`).
- `%p`: Prints a `void *` pointer argument in hexadecimal format (prefixed with `0x` and outputs `(nil)` if the pointer is null).
- `%d` / `%i`: Prints a signed base 10 integer (fully protects against `INT_MIN` overflow).
- `%u`: Prints an unsigned base 10 decimal number.
- `%x`: Prints a number in lowercase hexadecimal (base 16) format.
- `%X`: Prints a number in uppercase hexadecimal (base 16) format.
- `%%`: Prints a literal percent sign.

### Detailed Algorithm Explanation & Justification
Unlike naive approaches that allocate dynamic memory (`malloc`) to convert integers or hexadecimals into temporary strings, this library implements a **Low-Memory Recursive Decomposition Algorithm**.

#### Technical Choices & Architectural Justifications:
- **Zero-Malloc Numeric Conversions**: For `%d`, `%i`, `%u`, `%x`, and `%X`, the numbers are broken down mathematically by base division (e.g., base 10 or base 16) through recursion. Characters are printed from the deepest recursive stack level upwards. This approach eliminates the risk of heap memory leaks and reduces memory overhead.
- **Memory Protection & Safe Linear Traversal**: Character and string printing are completely linear. String pointers are guarded against `NULL` states prior to any read operation, effectively preventing unpredictable Segmentation Faults.

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