//
// Created by christian on 27/04/24.
//
#include <unistd.h>
#include "utils.h"

void ft_putchar(char c)
{
    write(1, &c, 1);
}

int ft_strlen(const char *str)
{
    int len = 0;
    while (str[len])
        len++;
    return len;
}

void ft_putstr(const char *str)
{
    while (*str)
        ft_putchar(*str++);
}

void ft_strcpy(char *dest, const char *src)
{
    while (*src)
        *dest++ = *src++;
    *dest = '\0';
}

void ft_putnbr(int num)
{
    if (num == -2147483648)
    {
        ft_putstr("-2147483648");
        return;
    }
    if (num < 0)
    {
        ft_putchar('-');
        num = -num;
    }
    if (num >= 10)
        ft_putnbr(num / 10);
    ft_putchar((num % 10) + '0');
}

int ft_atoi(const char *str)
{
    int result = 0;
    int sign = 1;
    while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
        str++;
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            sign = -1;
        str++;
    }
    while (*str >= '0' && *str <= '9')
    {
        result = result * 10 + (*str - '0');
        str++;
    }
    return result * sign;
}
