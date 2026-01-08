#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ft_length (char * sentence, char s){

    int counter_words = 0;
    int global_counter_letters = 0;
    int counter_space = 0;
    int counter_letters = 0;
    int i = 0;

    if(sentence == NULL)
    return -1;

    while(sentence[i] != '\0'){

        if(sentence[i] == s)
        counter_space++;

        i++;
    }
    global_counter_letters = strlen(sentence);
    global_counter_letters -= counter_space;

    //printf("global_counter_letters = %d\n", global_counter_letters);

    i = 0;

    while(sentence[i] != '\0'){

        

        if(sentence[i] != s){
            counter_letters++;
        }

        if(sentence[i] == s && counter_letters != 0){
        counter_words++;
        global_counter_letters -= counter_letters;
        counter_letters = 0;
        }
        i++;
        
    }
    //printf("global_counter_letters = %d\n", global_counter_letters);
    //printf("counter_space = %d\n", counter_space);
    //printf("strlen = %ld\n", strlen(sentence));

    if(global_counter_letters != 0)
    counter_words++;

    return counter_words;


}

int main(int ac, char **av){


printf("words = %d\n", ft_length(av[1], 'u'));


    return(0);
}