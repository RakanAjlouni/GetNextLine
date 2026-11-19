*This activity has been created as part of the 42 curriculum by rajlouni.*

## Description

**get_next_line** is a C programming project that introduces the concept of static variables in C. The goal of this project is to create a function that reads a single line from a file descriptor (`fd`), dynamically allocating exactly enough memory for that line. It correctly manages leftover characters between consecutive function calls without losing data, allowing a file to be read line by line until the end of the file is reached.

## Instructions

1. **Get the files:** Clone the repository and navigate into the root directory.

2. **Compile:** You must define the `BUFFER_SIZE` macro at compile time to specify how many bytes `read()` should process at once. Use the standard 42 compiler flags:
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl
```

3. **Include it:** To use this function in your own projects, add `#include "get_next_line.h"` to your C files and compile your project alongside `get_next_line.c` and `get_next_line_utils.c`.

## Resources

* **Documentation:** The man7.org website and system manuals (`man 2 read`, `man 3 malloc`, `man 3 free`) were used as the primary references for understanding the exact expected behaviors, return values, and memory management rules.
* **AI Usage:** AI was used for navigating logical traps and gaining a deep understanding of specific concepts, such as pointer reassignment and static variable behavior. It acted as a Socratic tutor when needed.

## Algorithm Explanation & Justification

This project was built using a strict modular architecture divided into four specific functions. This algorithm was chosen to guarantee complete memory safety, prevent dangling pointers.

**Architecture Details**
* **`read_and_stash`**: Handles the system I/O. It reads chunks of `BUFFER_SIZE` bytes into a temporary buffer and continuously appends them to the static `stash` variable using `ft_strjoin` until a newline character (`\n`) is encountered or the end of the file is reached.

* **`extract_line`**: Isolates the valid line to return to the user. It measures the `stash` up to the first `\n`, dynamically allocates exactly enough memory, and performs a 1-to-1 copy while ensuring proper null-termination.

* **`clean_stash`**: Acts as the garbage collector and state preserver. It identifies any leftover characters that exist after the `\n` in the original stash, allocates a new string to save them, completely frees the old stash to prevent memory leaks, and returns the new pointer.

* **`get_next_line`**: The main orchestrator. Verifies the validity of the file descriptor and buffer size, executes the three helper functions in strict sequence, and safely updates the static variable for subsequent calls.

**Justification**
A monolithic approach to this project often results in deep nesting, complex edge-case tracking, and severe memory leaks. By separating the logic into dedicated micro-tools (reading, slicing, and garbage collection), the algorithm strictly compartmentalizes memory allocations. Temporary buffers are freed immediately after use, ensuring maximum efficiency and code readability.
