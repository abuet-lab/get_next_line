# get_next_line

![Language](https://img.shields.io/badge/language-C-blue)
![School](https://img.shields.io/badge/school-42-black)

A C function that reads a file descriptor **one line at a time**, no matter the size of the read buffer. Calling it repeatedly returns the file line by line until the end is reached.

> Project from the [42 school](https://42.fr/) curriculum, written in C under strict constraints: no standard library functions other than `read`, `malloc` and `free`, and compliance with the 42 coding standard (the *Norm*).

---

## Prototype

```c
char *get_next_line(int fd);
```

| Return value | Meaning |
|--------------|---------|
| A line       | The next line read from `fd`, including the trailing `\n` (except at end of file if the file does not end with one) |
| `NULL`       | Nothing left to read, or an error occurred |

The returned line is allocated with `malloc` and must be freed by the caller.

## How it works

The function relies on a **static variable** that keeps leftover data between calls:

1. Read from `fd` in chunks of `BUFFER_SIZE` bytes and append them to the stored buffer, until a `\n` is found or the end of the file is reached.
2. Extract everything up to and including the first `\n`: this is the line returned to the caller.
3. Keep the remaining characters in the static buffer for the next call.
4. Free all memory once the end of the file is reached or if an error occurs.

This approach works with any `BUFFER_SIZE` (from 1 to very large values) and reads only as much as needed, instead of loading the whole file into memory.

## Project structure

```text
.
├── get_next_line.c        # Main logic: reading, line extraction, leftover handling
├── get_next_line_utils.c  # Helper string functions
├── get_next_line.h        # Prototypes and BUFFER_SIZE default
├── main.c                 # Small test program
└── test.txt               # Sample input file
```

## Usage

### Compile

The buffer size is set at compile time with the `BUFFER_SIZE` macro:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl
```

### Example

```c
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
    int   fd;
    char  *line;

    fd = open("test.txt", O_RDONLY);
    if (fd < 0)
        return (1);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

```bash
./gnl
```

It also works with standard input (`fd = 0`).

## Testing

Try several buffer sizes to check edge cases:

```bash
for size in 1 2 42 1000 10000000; do
    cc -Wall -Wextra -Werror -D BUFFER_SIZE=$size get_next_line.c get_next_line_utils.c main.c -o gnl
    ./gnl
done
```

Check for memory leaks:

```bash
valgrind --leak-check=full ./gnl
```

Edge cases covered: empty files, files without a trailing newline, very long lines, `BUFFER_SIZE=1`, and invalid file descriptors.

## What I learned

- Using **static variables** to keep state between function calls
- Managing **dynamic memory** carefully in C (allocation, freeing, avoiding leaks)
- Working with **file descriptors** and the low-level `read` system call
- Handling edge cases and writing robust code under strict constraints
