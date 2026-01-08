
#include "../includes/libft.h"


void ft_toupper(char *str){

    int i = 0;

    while(str[i] != '\0'){
        if(str[i] >= 41 && str[i] <= 90)
        putchar(str[i]);
        else
        putchar(str[i] - ' ');
        
        i++;

    }
}