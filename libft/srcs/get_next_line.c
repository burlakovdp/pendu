#include "../includes/libft.h"

char * ft_delete_str(char * new_line, char * str){

    char * res;
    int length = 0;
    if(new_line == NULL || str == NULL)
        return NULL;
    length = ft_strlen(new_line) + 1;
    
    res = ft_strdup(str+length);
    if(str)
        free(str);

    if(res == NULL)
        return NULL;
    return res;
}

char * ft_free_cat(char * a, char * b){

    char * res; // = ft_strjoin(a, b);

    if(a == NULL){
        res = ft_strdup(b);
    }
    else{
        res = ft_strjoin(a, b);
        free(a);
    }
    // si a est null -> res ->strdup b et return res;
    //sinon join et free(a) return res
    return res;
} 

char * ft_creat(char * str, int * flag){

    int length = 0;
    char * res;
    if(ft_strchr(str, '\n') == 1){
        *flag = 1;
        while(str[length] != '\n'){
            length++;
        }
    }
    else
    {
        *flag = 0;
        length = ft_strlen(str);
    }
    
    res = malloc(sizeof(char) * (length+1));

    if(res == NULL)
        return NULL; 

    int i = 0;

    while(i < length){
        res[i] = str[i];
        i++;
    }
    res[i] = '\0';
    return res;
}

int get_next_line(const int fd, char** line){

    if (fd < 0 || line == NULL || BUFF_SIZE <= 0)
        return -1;

    static char * str = NULL;
    char * new_line; 
    int ret = 0;
    int flag = 0;
    char buffer[BUFF_SIZE+1];
    
    while((ret = read(fd, buffer, BUFF_SIZE)) > 0)
    {
        buffer[ret] = '\0';
        if((str = ft_free_cat(str, buffer)) == NULL)
            return -1;
        if (ft_strchr(buffer, '\n') == 1)
            break;
    }

    if((new_line = ft_creat(str, &flag)) == NULL){
        free(str);
        return -1;
    }
    *line = new_line;
    if((str = ft_delete_str(new_line, str)) == NULL){
        free(new_line);
        return -1;
    }
    return flag;
}