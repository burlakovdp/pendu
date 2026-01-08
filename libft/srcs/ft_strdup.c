#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void ft_putchar(char str){

    write(2, &str, 1);

}

void ft_putstr(char * str){
    int counter = 0;
    
    while(str[counter] != '\0'){
        write(1, &str[counter], 1);
        counter++; 
    }

    write(1, "\n", 1);
}

char * ft_strdup(char *str){

    if(str == NULL){
        return NULL;
    } 

    int memoryCounter = 0;
    
    while(str[memoryCounter] != '\0'){
        memoryCounter++;
    }

    char * res = malloc((memoryCounter + 1) * sizeof(char));

    for(int i = 0; i < memoryCounter; i++){
        res[i] = str[i];
    }
    res[memoryCounter] = '\0';
    
    return res;

}