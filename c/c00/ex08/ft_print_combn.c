/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 20:17:52 by chrrodri          #+#    #+#             */
/*   Updated: 2024/03/31 20:25:42 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_comb(int n, int prev, int depth, int prime)
{
	char	c;
	int		i;

	i = prev + 1;
	while (i <= 10 - n + depth)
	{
		c = '0' + i;
		ft_putchar(c);
		if (n - 1 > 0)
		{
			print_comb(n - 1, i, depth + 1, 0);
		}
		else if (i < 9)
		{
			if (!prime || depth != 0)
			{
				write(1, ", ", 2);
			}
		}
		i++;
	}
}

void	ft_print_combn(int n)
{
	int		i;
	int		prime;

	i = 0;
	prime = 1;
	if (n < 1 || n > 9)
		return;
	while (i <= 10 - n)
	{
		if (!prime)
		{
			write(1, ", ", 2);
		}
		ft_putchar('0' + i);
		if (n - 1 > 0)
		{
			print_comb(n - 1, i, 1, prime);
		}
		i++;
		prime = 0;
	}
}
