#include "../includes/libft.h"

void ft_putchar_fd(char str, int fd){

    write(fd, &str, 1);

}