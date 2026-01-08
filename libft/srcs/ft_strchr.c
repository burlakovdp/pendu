#include "../includes/libft.h"

int ft_strchr(char* str, char c){

    if(str == NULL)
        return -1;

    int i = 0;

    while(str[i] != '\0'){

        if(str[i] == c)
            return 1;
        i++;
    }
    return(0);
}