#include "../includes/libft.h"

int ft_atoi(char *a){

    int res = 0;
    int c = 1;
    int counter = 0;
    int memory = 1;
    int n = 0;
    
    while(a[counter] != '\0'){
        counter++;
    }
    if (a[0] == 45){
        memory = memory * -1;
        n = 1;
    }

    for(int i = 0; i < counter-1-n; i++){
        
        c *= 10;
    }
    for(int i = 0 + n; i < counter; i++){
        
        res += (a[i] - '0') * c;
        c /= 10;
    }
    return (res * memory);

}