#include <unistd.h>
#include "utils.h"

void	ft_putchar(char c);

void    ft_putnbr(int num);

int     ft_atoi(char *str);

int		ft_recursive_factorial(int nb)
{
	if (nb > 12 || nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	else
		return (nb * ft_recursive_factorial(nb - 1));
}


int main (int argc, char **argv)
{
    int nb;

    if (argc < 2)
    {
        write (2, "Error, no input!\n", 17);
        return (1);
    }
    nb = ft_atoi(argv[1]);
    ft_putnbr(ft_recursive_factorial(nb));
    ft_putchar('\n');
    return (0);
}