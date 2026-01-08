#include "header.h"

int random_int()
{
    int nombre = 0;
    const int MIN = 0, MAX = 96;
    srand(time(NULL)); // Initialisation de la donnée seed

    nombre = (rand() % (MAX + 1 - MIN)) + MIN; // MIN <= nombre <= MAX
    //printf("%d", nombre); // rand  renvoie un nombre calculé à partir de la donnée seed
    return nombre;
}


char * ft_word(){
    int fd = 0;
    char ** res;
    fd = open("./text.txt", O_RDONLY);
    if(fd < 0){
        return (NULL);
    }
    
    res = malloc(sizeof(char**) * 1);
    for(int j = 0; j < 97; j++){
        res[j] = malloc(sizeof(char) * 15);
    }
    if(res == NULL){
        return NULL;
    };
    //printf("fd => %d\n", fd);
    res[97] = NULL;
    int i = 0;
    while(get_next_line(fd, &res[i]) != 0){
        i++;
    }
    i = random_int();
    char * word;
    word = ft_strdup(res[i]);
    return word;
}

int ft_c2i(char str){
    //printf("ICI");
    int res = str;
    return res;

}

int ft_pendu(char * word){
    
    char * line;
    char * saveWord;
    line = ft_strdup(word);
    saveWord = ft_strdup(word);
    
    for(int i = 0; i < ft_strlen(word); i++){
        line[i] = '_';
    }
    line[ft_strlen(word)+1] = '\0';
    
    char * luckyWord = malloc(sizeof(char));       
    int winCounter = ft_strlen(word) + 20;
    //printf("w => %d\n", winCounter);
    int memoP = 0;
    ft_putstr(line);

    while(winCounter > 0){
        if(memoP == ft_strlen(word)){
            //ft_putstr(line);
            printf("You win!\n");
            goto A;
        }
        printf("Nombre(s) d'essai(s) : %d\n", winCounter);
        get_next_line(0, &luckyWord);
        int i = 0;
        int flag = 0;
        while(saveWord[i] != '\0'){
            if(saveWord[i] == luckyWord[0]){
                line[i] = saveWord[i];
                saveWord[i] = '_';
                memoP++;
                flag++;
            }   
            i++;
        } 
        
        if(flag == 0){
            ft_putstr("Wrong letter!");
            ft_putstr(line);
        }
        else{
            ft_putstr(line);
        }
        winCounter--; 
            
    }
    printf("You lost!\n");
A:
    free(line);
    free(saveWord);
    free(luckyWord);
    return 1;
}

int main(){
    //printf("ICI");
    ft_pendu(ft_word());
    //printf("i => %d\n", i);

    return(0);
}