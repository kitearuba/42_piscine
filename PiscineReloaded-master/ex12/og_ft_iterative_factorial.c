
#include <unistd.h>

int	ft_iterative_factorial(int nb)
{
	int		res;

	res = 1;
	if (nb > 12 || nb < 0)
		return (0);
	else
	{
		while (nb > 0)
		{
			res *= nb;
			nb--;
		}
		return (res);
	}
}

int ft_atoi(char *str)
{
    int i;
    int sign;
    int num;

    i = 0;
    sign = 1;
    num = 0;
    if (str[i] == '\0')
        write (2, "Error, no input!\n", 17);
    while (str[i] < 33)
        i++;
    if (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-')
            sign *= -1;
        i++;
    }
    while(str[i] > 47 && str[i] < 58)
    {
        if (num == 0)
            num = str[i] - 48;
        else
            num = (num * 10) + str[i] - 48;
	i++;
    }
    return (sign * num);
}

void ft_putchar(char c)
{
    write (1, &c, 1);
}

void ft_putnbr(int num)
{
	if (num > 9)
        ft_putnbr(num / 10);
    ft_putchar( num % 10 + '0');
}

int main(int argc, char **argv)
{
    int nb;
    int	result;

    if (argc < 2)
    {
        write (2, "Error, no input!\n", 17);
        return (1);
    }
    nb = ft_atoi(argv[1]);
    result = ft_iterative_factorial(nb);
    ft_putnbr(result);
    ft_putchar('\n');
    return (0);
}
