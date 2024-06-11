#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int size;

	i = 0;
	size = sizeof(argc) / sizeof(argc[0]);
	ft_putnbr(sizei;
	ft_strlen();
	while (argv [i] != '\0')
	{
		ft_putstr(argv[i]);
		i++;
	}
	return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void ft_putnbr(int nbr)
{
	if (num < 0)
	{
		ft_putchar('-');
		num = -num;
	}
	if (num > 9)
		ft_putnbr(num / 10);
	ft_putchar(num % 10 + '0');
}
