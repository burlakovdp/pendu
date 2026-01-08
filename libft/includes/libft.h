#ifndef LIBFT_H
#define LIBFT_H
#define BUFF_SIZE 4096

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int ft_strcomp(char * a, char * b);
int ft_strlen(char* str);
void ft_putstr_fd(char * str, int fd);
void ft_putchar_fd(char str, int fd);
int ft_atoi(char *a);
char **ft_split(char *str, char sep);
int get_next_line(const int fd, char** line);
int ft_strchr(char* str, char c);
char * ft_strjoin(char * a, char * b);
char * ft_strdup(char *str);
void ft_putchar(char str);
void ft_putstr(char * str);
char* ft_strcopy(char*src, char*dest);


#endif
