/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 17:45:11 by chrrodri          #+#    #+#             */
/*   Updated: 2024/04/03 13:23:37 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size);

void	ft_putnbr(int nbr);

void	ft_putchar(char c);

int	main(void)
{
	int	arr[] = {0, 1, -2, 3, 4, 5555, 6, 7};
	int	*ta;
	int i;
	ta = arr;
	int	size = sizeof(arr) / sizeof(arr[0]);
	ft_rev_int_tab(ta, size);
	i = 0;
    while (i < size )
    {
        ft_putnbr(arr[i]);
        i++;
    }
	return (0);
}

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < size / 2)
	{
		tmp = tab[i];
		tab[i] = tab[size - i - 1];
		tab[size - i - 1] = tmp;
		i++;
	}
}

void	ft_putnbr(int nbr)
{
	if (nbr == -2147483648)
	{
		ft_putchar('-');
		ft_putnbr(214748364);
		ft_putchar('8');
	}
	else
	{
		if (nbr < 0)
		{
			ft_putchar('-');
			nbr = -nbr;
		}
		if (nbr > 9)
			ft_putnbr(nbr / 10);
		ft_putchar(nbr % 10 + '0');
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
