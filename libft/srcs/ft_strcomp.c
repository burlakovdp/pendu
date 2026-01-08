#include "../includes/libft.h"

int ft_strcomp(char * a, char * b){

    if(a == NULL || b == NULL){
        return -1;
    }

    for(int i = 0; i < 4; i++){

        if(a[i]-'0' != b[i]-'0'){
            
            return 1;
        }

    }

    return 0;
}