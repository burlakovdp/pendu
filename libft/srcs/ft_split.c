#include "../includes/libft.h"

int ft_find(char c, char sep)
{
    if (c == sep || c == '\0')
        return(1);
    else
        return 0;
}

int ft_countwords(char *str, char sep)
{
    int i = 0;
    int word = 0;
    while(str[i])
    {
        if (ft_find(str[i + 1], sep) == 1 && ft_find(str[i], sep) == 0)
            word++;
        i++;
    }
    return (word);
}

void ft_copy(char *src, char *dest, char sep)
{
    int i = 0;
    while(ft_find(src[i], sep) != 1)
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

void ft_transfert_content(char **tab, char *str, char sep)
{
    int i = 0;
    int j = 0;
    int k = 0;

    while (str[i])
    {
        if (ft_find(str[i], sep) == 1)
            i++;
        else
        {
            j = 0;
            while (ft_find(str[i + j], sep) == 0)
                j++;
            tab[k] = malloc(sizeof(char) * (j + 1));
            if (tab[k] == NULL)
                return ;
            ft_copy(str + i, tab[k], sep);
            k++;
            i = i + j;
        }
    }
}
char **ft_split(char *str, char sep)
{
    int words = ft_countwords(str, sep);
    char **tab;

    tab = malloc(sizeof(char *) * words + 1);
    if (tab == NULL)
        return (NULL);
    tab[words] = NULL;
    ft_transfert_content(tab, str, sep);
    return (tab);

}