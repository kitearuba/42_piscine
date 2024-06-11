//
// Created by christian on 27/04/24.
//
#include <unistd.h>
/*
void *ft_memset(void *s, int c, size_t n);
void *ft_memset(void *s, int c, size_t n)
{

}

void ft_bzero(void *s, size_t n);
void ft_bzero(void *s, size_t n)
{

}

• memcpy
• memccpy
• memmove
• memchr
• memcmp
 */
void    ft_putchar(char c)
{
    write (1, &c, 1);
}
/*
• strdup
• strcpy
• strncpy
• strcat
• strncat
• strlcat
• strchr
• strrchr
• strstr
• strnstr
• strcmp
• strncmp
• atoi
• isalpha
        isdigit
• isalnum
• isascii
• isprint
• toupper
• tolower#include "utils.h"
*/

// STRINGS

void ft_strcpy(char *dest, const char *src)
{
    int i;

    i = 0;
    while (src[i] != '\0')
    {
        dest[i] =  src[i];
        i++;
    }
    dest[i] = '\0';
}

int ft_strlen(const char *str)
{
    int i;

    i = 0;
    while ( str[i] != '\0')
    {
        i++;
    }
    return (i);
}

void    ft_putstr (char *str)
{
    int i;

    i = 0;
    while (str[i] != '0')
    {
        ft_putchar(str[i]);
        i++;
    }
}

//  NUMBERS

void    ft_putnbr(int nbr)
{
    if (nbr < 0) {
        ft_putchar('-');
        nbr = -nbr;
    }
    if (nbr > 9)
        ft_putnbr(nbr / 10);
    ft_putchar((nbr % 10) + '0');
}

int ft_atoi(char *str)
{
    int i;
    int sign;
    int nbr;

    i = 0;
    sign = 1;
    nbr = 0;
    if (str[i] == '\0')
        write (2, "Error, no input!\n", 17);
    while (str[i] < 33)
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i] > 47 && str[i] < 58)
    {
        if (nbr == 0)
            nbr = str[i] - 48;
        else
            nbr = (nbr * 10) + (str[i] - 48);
        i++;
    }
    return (sign * nbr);
}

