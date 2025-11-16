# mlib - C Standard Library Implementation

A learning project to implement the C Standard Library from scratch as an educational exercise.

## 📚 Reference

- **C Standard (ISO/IEC 9899:2018)**: [Latest C Standard](https://www.iso.org/standard/74528.html)
- **C Standard Library Reference**: [cppreference.com](https://en.cppreference.com/w/c)
- **POSIX.1-2017**: [IEEE Standard](https://pubs.opengroup.org/onlinepubs/9699919799/)

## 🎯 Project Goals

This project aims to:

- Deepen understanding of C programming and system-level concepts
- Learn memory management, I/O operations, and low-level programming
- Practice implementing well-defined specifications
- Build a comprehensive test suite
- Understand the complexity behind "simple" library functions

## 📋 Development Guidelines

### Core Principles

- **Avoid Premature Optimization**: Get it working first, then make it fast
- **Incremental Development**: Work in small, testable steps
- **Test-Driven Development**: Write tests before or alongside implementation
- **Documentation**: Document every function's behavior, edge cases, and assumptions
- **Standard Compliance**: Follow C standard specifications closely
- **Error Handling**: Handle edge cases and error conditions properly

### Development Process

1. **Research**: Study the standard specification for each function
2. **Design**: Plan the implementation approach
3. **Implement**: Write the basic working version
4. **Test**: Create comprehensive test cases
5. **Optimize**: Improve performance where necessary
6. **Document**: Add proper documentation and examples

### Progress Tracking Legend

- ⚪ Not Started
- 🟡 Working (basic implementation complete)
- 🟠 Optimized (performance improvements applied)
- 🟢 Production-ready (thoroughly tested, documented, edge cases handled)

## 🗂 Implementation Roadmap

### Phase 1: String Manipulation (Easy Start)

Basic string operations to get familiar with the codebase structure.

#### `<string.h>`

- [X] 🟡 `strlen` - Calculate string length
- [x] 🟡 `strcpy` - Copy string
- [x] 🟡 `strncpy` - Copy string with length limit
- [x] 🟡 `strcat` - Concatenate strings
- [x] 🟡 `strncat` - Concatenate strings with length limit
- [x] ⚪ `strcmp` - Compare strings
- [ ] ⚪ `strncmp` - Compare strings with length limit
- [ ] ⚪ `strchr` - Find character in string
- [ ] ⚪ `strrchr` - Find last occurrence of character
- [ ] ⚪ `strstr` - Find substring
- [ ] ⚪ `strspn` - Get span of characters in set
- [ ] ⚪ `strcspn` - Get span of characters not in set
- [ ] ⚪ `strpbrk` - Find first occurrence of characters from set
- [ ] ⚪ `strtok` - Split string into tokens
- [ ] ⚪ `strdup` - Duplicate string (POSIX)

### Phase 2: Character Classification & Conversion

Simple character operations with lookup tables.

#### `<ctype.h>`

- [ ] ⚪ `isalpha` - Check if alphabetic
- [ ] ⚪ `isdigit` - Check if digit
- [ ] ⚪ `isalnum` - Check if alphanumeric
- [ ] ⚪ `isspace` - Check if whitespace
- [ ] ⚪ `isupper` - Check if uppercase
- [ ] ⚪ `islower` - Check if lowercase
- [ ] ⚪ `ispunct` - Check if punctuation
- [ ] ⚪ `isprint` - Check if printable
- [ ] ⚪ `isgraph` - Check if graphic character
- [ ] ⚪ `iscntrl` - Check if control character
- [ ] ⚪ `isxdigit` - Check if hexadecimal digit
- [ ] ⚪ `toupper` - Convert to uppercase
- [ ] ⚪ `tolower` - Convert to lowercase

### Phase 3: Memory Operations

Essential memory manipulation functions.

#### `<string.h>` (Memory functions)

- [ ] ⚪ `memcpy` - Copy memory block
- [ ] ⚪ `memmove` - Move memory block (handles overlap)
- [ ] ⚪ `memset` - Fill memory with value
- [ ] ⚪ `memcmp` - Compare memory blocks
- [ ] ⚪ `memchr` - Find byte in memory

### Phase 4: String Conversion & Parsing

Number parsing and conversion functions.

#### `<stdlib.h>` (String conversion)

- [ ] ⚪ `atoi` - String to integer
- [ ] ⚪ `atol` - String to long
- [ ] ⚪ `atoll` - String to long long
- [ ] ⚪ `atof` - String to double
- [ ] ⚪ `strtol` - String to long (advanced)
- [ ] ⚪ `strtoll` - String to long long (advanced)
- [ ] ⚪ `strtoul` - String to unsigned long
- [ ] ⚪ `strtoull` - String to unsigned long long
- [ ] ⚪ `strtod` - String to double (advanced)
- [ ] ⚪ `strtof` - String to float
- [ ] ⚪ `strtold` - String to long double

### Phase 5: Dynamic Memory Management

Core memory allocation functions.

#### `<stdlib.h>` (Memory management)

- [ ] ⚪ `malloc` - Allocate memory
- [ ] ⚪ `calloc` - Allocate and zero memory
- [ ] ⚪ `realloc` - Reallocate memory
- [ ] ⚪ `free` - Free allocated memory
- [ ] ⚪ `aligned_alloc` - Aligned memory allocation (C11)

### Phase 6: Basic Math Functions

Essential mathematical operations.

#### `<math.h>` (Basic functions)

- [ ] ⚪ `abs` - Absolute value (integer)
- [ ] ⚪ `labs` - Absolute value (long)
- [ ] ⚪ `llabs` - Absolute value (long long)
- [ ] ⚪ `fabs` - Absolute value (double)
- [ ] ⚪ `fabsf` - Absolute value (float)
- [ ] ⚪ `fabsl` - Absolute value (long double)
- [ ] ⚪ `fmod` - Floating-point remainder
- [ ] ⚪ `remainder` - IEEE remainder
- [ ] ⚪ `ceil` - Ceiling function
- [ ] ⚪ `floor` - Floor function
- [ ] ⚪ `trunc` - Truncate to integer
- [ ] ⚪ `round` - Round to nearest integer

### Phase 7: Formatted I/O (Complex!)

String formatting and parsing - very complex implementations.

#### `<stdio.h>` (String formatting)

- [ ] ⚪ `sprintf` - Format string to buffer
- [ ] ⚪ `snprintf` - Format string to buffer (safe)
- [ ] ⚪ `sscanf` - Parse formatted string
- [ ] ⚪ `vsprintf` - Format string with va_list
- [ ] ⚪ `vsnprintf` - Format string with va_list (safe)
- [ ] ⚪ `vsscanf` - Parse formatted string with va_list

### Phase 8: Advanced Math Functions

Trigonometric, exponential, and logarithmic functions.

#### `<math.h>` (Advanced functions)

- [ ] ⚪ `sqrt` - Square root
- [ ] ⚪ `pow` - Power function
- [ ] ⚪ `exp` - Exponential function
- [ ] ⚪ `log` - Natural logarithm
- [ ] ⚪ `log10` - Base-10 logarithm
- [ ] ⚪ `sin` - Sine
- [ ] ⚪ `cos` - Cosine
- [ ] ⚪ `tan` - Tangent
- [ ] ⚪ `asin` - Arc sine
- [ ] ⚪ `acos` - Arc cosine
- [ ] ⚪ `atan` - Arc tangent
- [ ] ⚪ `atan2` - Arc tangent of y/x
- [ ] ⚪ `sinh` - Hyperbolic sine
- [ ] ⚪ `cosh` - Hyperbolic cosine
- [ ] ⚪ `tanh` - Hyperbolic tangent

### Phase 9: Random Number Generation

Pseudo-random number generation.

#### `<stdlib.h>` (Random functions)

- [ ] ⚪ `rand` - Generate random number
- [ ] ⚪ `srand` - Seed random number generator

### Phase 10: Utility Functions

Miscellaneous utility functions.

#### `<stdlib.h>` (Utilities)

- [ ] ⚪ `qsort` - Quick sort implementation
- [ ] ⚪ `bsearch` - Binary search
- [ ] ⚪ `div` - Integer division with remainder
- [ ] ⚪ `ldiv` - Long division with remainder
- [ ] ⚪ `lldiv` - Long long division with remainder

### Phase 11: File I/O (Very Complex!)

File operations and stream I/O.

#### `<stdio.h>` (File operations)

- [ ] ⚪ `fopen` - Open file
- [ ] ⚪ `fclose` - Close file
- [ ] ⚪ `fread` - Read from file
- [ ] ⚪ `fwrite` - Write to file
- [ ] ⚪ `fseek` - Seek in file
- [ ] ⚪ `ftell` - Get file position
- [ ] ⚪ `rewind` - Rewind file
- [ ] ⚪ `fgetc` - Get character from file
- [ ] ⚪ `fputc` - Put character to file
- [ ] ⚪ `fgets` - Get string from file
- [ ] ⚪ `fputs` - Put string to file
- [ ] ⚪ `fprintf` - Formatted output to file
- [ ] ⚪ `fscanf` - Formatted input from file
- [ ] ⚪ `fflush` - Flush file buffer
- [ ] ⚪ `ferror` - Check for file errors
- [ ] ⚪ `feof` - Check for end of file
- [ ] ⚪ `clearerr` - Clear error flags

### Phase 12: Advanced Features (Expert Level)

Complex implementations requiring deep system knowledge.

#### `<setjmp.h>`

- [ ] ⚪ `setjmp` - Set jump point
- [ ] ⚪ `longjmp` - Long jump

#### `<signal.h>`

- [ ] ⚪ `signal` - Set signal handler
- [ ] ⚪ `raise` - Raise signal

#### `<time.h>`

- [ ] ⚪ `time` - Get current time
- [ ] ⚪ `clock` - Get processor time
- [ ] ⚪ `difftime` - Compute time difference
- [ ] ⚪ `mktime` - Convert tm to time_t
- [ ] ⚪ `strftime` - Format time string
- [ ] ⚪ `gmtime` - Convert to UTC
- [ ] ⚪ `localtime` - Convert to local time
- [ ] ⚪ `asctime` - Convert tm to string
- [ ] ⚪ `ctime` - Convert time_t to string

## 🧪 Testing Strategy

### Test Categories

1. **Unit Tests**: Test individual functions in isolation
2. **Integration Tests**: Test function interactions
3. **Performance Tests**: Benchmark against system implementations
4. **Edge Case Tests**: Handle boundary conditions and error cases
5. **Compliance Tests**: Verify standard compliance

### Test Framework

Consider using a lightweight testing framework like:

- **Unity** - Simple C testing framework
- **MinUnit** - Minimal unit testing framework

## 📁 Project Structure

```
mlib/
├── include/           # Header files
│   ├── string.h
│   ├── stdio.h
│   ├── stdlib.h
│   ├── math.h
│   └── ...
├── src/               # Implementation files
│   ├── string/
│   ├── stdio/
│   ├── stdlib/
│   ├── math/
│   └── ...
├── tests/             # Test files
│   ├── test_string.c
│   ├── test_stdio.c
│   └── ...
├── benchmarks/        # Performance tests
├── docs/              # Documentation
├── examples/          # Usage examples
└── Makefile          # Build configuration
```

## 🔧 Build System

Use a simple Makefile or modern build system like CMake to:

- Compile the library
- Run tests
- Generate documentation
- Create benchmarks
- Install the library

## 📈 Progress Tracking

Update the checkboxes above as you complete each phase:

- First checkbox (🟡): Basic working implementation
- Second checkbox (🟠): Optimized version with performance improvements
- Third checkbox (🟢): Production-ready with full test coverage and documentation

## 🎓 Learning Resources

- **"The C Programming Language"** by Kernighan & Ritchie
- **"Advanced Programming in the UNIX Environment"** by Stevens & Rago
- **"Computer Systems: A Programmer's Perspective"** by Bryant & O'Hallaron
- **glibc source code** - Study real-world implementations
- **musl libc** - Clean, modern C library implementation
