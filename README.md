# Get_next_line

![status](https://img.shields.io/badge/status-finished-success)
![Language](https://img.shields.io/badge/language-C-blue)

## A function to read line by line a file

Get_next_line is a C function that uses a file descriptor to read line by line any file. It introduces the use of static variables and the concept of file descriptors, and, in my case, also serves as a good introduction to linked lists.

## A very non efficient GNL

Indeed, I used linked list to do this project because I wanted to better understand pointers and memory management, and to get hands-on experience with linked lists for future projects. However, I know that in this case it uses significantly more memory than a simple array of chars and is slower due to all the pointer manipulation required.

## Installation

bash
```
# Clone repository
git clone https://github.com/yannallo/get_next_line.git

# Enter directory
cd get_next_line
```

# Usage

Just include the header in your file and link during compilation.
e.g:

Bash
```
gcc main.c get_next_line.c get_next_line_utils.c
```

main.c
```
#include "get_next_line.h"
#include <fcntl.h>

int main(void)
{
  char *buf;
  int  fd = open("file_to_read", O_RDONLY);

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
