#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>

#include <stdio.h>
//GNL
char *get_next_line(int fd);

//GNL UTILS
size_t ft_strlen_gnl(const char *str);
char *ft_substr_gnl(char const *s, unsigned int start, size_t len);
char *ft_strchr_gnl(const char *s, int c);
char *ft_strjoin_gnl(char *s1, char const *s2);

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 8
#endif

#endif
