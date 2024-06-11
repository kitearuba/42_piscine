//
// Created by christian on 24/05/24.
//
#include <unistd.h>
#include <stdlib.h>
#include "utils.h"

void    ft_putchar(char c);
int     ft_strlen(const char *str);
void	ft_putstr(const char *str);
void    ft_strcpy(char *dest, const char *src);
char    *ft_strdup(const char *s);


int main (int argc, char **argv)
{
    char *s1;
    char *s2;

    if (argc <2)
    {
        write (2, "Error, no input!\n", 17);
        return (1);
    }
    s1 = argv[1];
    s2 = ft_strdup(s1);
    if (s2[0] == '\0')
    {
        write(2, "Error, memory allocation failed!\n", 33);
        return (1);
    }
    ft_putstr(s1);
    ft_putchar('\n');
    ft_putstr(s2);
    ft_putchar('\n');
    free( s2);
    return (0);
}

char *ft_strdup(const char *s)
{
    int lenth;
    char *str_copy;

    if (s == NULL)
        return (NULL);
    lenth = ft_strlen(s) + 1;
    str_copy = (char *)malloc(sizeof(char) * lenth);
    if (str_copy == NULL)
        return (NULL);
    ft_strcpy(str_copy, s);
    return (str_copy);
}
