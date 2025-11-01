# Get_next_line

![status](https://img.shields.io/badge/status-finished-success)
![Language](https://img.shields.io/badge/language-C-blue)
![Static Badge](https://img.shields.io/badge/Norminette-%E2%9C%93-success)

## A function to read line by line a file

`Get_next_line` is a C function that reads a file line by line using a file descriptors.
It introduces the use of static variables, file descriptors, and, in my case, served as a practical introduction to linked lists.

## A non-efficient GNL

For this implementation, I used a linked list to better understand pointers and memory management, and to gain hands-on experience with linked lists for future projects.
However, using linked lists is less memory-efficient and slower compared to a simple character array due to pointer manipulation.
A separate branch without linked lists is available for a more efficient version.

## Installation

```Bash
# Clone repository
git clone https://github.com/yannallo/get_next_line.git

# Enter directory
cd get_next_line
```

# Usage

Include the header in your file and link the source files during compilation.

```Bash
gcc main.c get_next_line.c get_next_line_utils.c -o test
```

### Example `main.c`
```C
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
  char *buf;
  int  fd = open("book.txt", O_RDONLY);

  if (fd == -1)
    return 1;
  buf = get_next_line(fd);
  while (buf)
  {
    printf("%s", buf);
    free(buf);
    buf = get_next_line(fd);
  }
  close(fd);
  return 0;
}
```

### Example `book.txt`
```txt
Lorem ipsum dolor sit amet, consectetuer adipiscing elit.
Aenean commodo ligula eget dolor.
Aenean massa.
Cum sociis natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus.
```
