#include "../includes/libft.h"

int counter (char* count);

char* ft_strcopy(char*src, char*dest){

    int i = 0;  
    if(!src){
        return (NULL);
    }
    while(i < counter(src)){
        dest[i] = src[i];
        i++;
        
    } 
    dest[i] = '\0';
    return dest;
}
int counter (char* count){
    int i;
    
    while(count[i]){
    i++;
    }
    
    if(i == 0){
    return (-1);
    }
    return i;

}