#include "../includes/libft.h"

void ft_destroy(char * a){
    free(a);
}

char * ft_strjoin(char * a, char * b){

    if(b == NULL || a == NULL)
        return NULL;

    char * res = malloc(sizeof(char *) * (ft_strlen(a) + ft_strlen(b) + 1));

    if (res == NULL)
        return NULL;

    int i = 0;
    for( ;i < ft_strlen(a); i++){

        res[i] = a[i];
    }
    int j = 0;
    for( ;j < ft_strlen(b); j++){

        res[i+j] = b[j];
    }

    res[i+j] = '\0';

    return res;
}