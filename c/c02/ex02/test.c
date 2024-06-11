#include <unistd.h>

int     ft_str_is_alpha(char *str);

void    ft_putchar(char c);

int     main(void)
{
    char str[] = "Hello";
    ft_str_is_alpha(str);
    return (0);
}

int     ft_str_is_alpha(char *str)
{       
    int     i;

    char    result = '1';
    i = 0;
    while (str[i] != '\0')
    {
        if (!((str[i] > 64 && str[i] < 91) || (str[i] > 96 && str[i] < 123)))
        {
            result = '0';
            break; 
        }
        i++;
    }
    ft_putchar(result);
    return result - '0';
}

void ft_putchar(char c)
{
    write(1, &c, 1);
}

