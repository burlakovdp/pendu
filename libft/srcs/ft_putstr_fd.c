#include "../includes/libft.h"

void ft_putstr_fd(char * str, int fd){
    int counter = 0;
    
    while(str[counter] != '\0'){
        write(fd, &str[counter], 1);
        counter++; 
    }

    write(1, "\n", 1);
}