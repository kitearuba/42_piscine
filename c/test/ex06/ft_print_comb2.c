/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:11:27 by chrrodri          #+#    #+#             */
/*   Updated: 2024/03/27 14:16:19 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb2(void);

void	print_set(char a, char x, char y, char z);

void	loop_check(char a, char x, char y, char z);

void	print_set(char a, char x, char y, char z)
{
	write(1, &a, 1);
	write(1, &x, 1);
	write(1, " ", 1);
	write(1, &y, 1);
	write(1, &z, 1);
	if (!(a == '9' && x == '8' && y == '9' && z == '9'))
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb2(void)
{
	char	a;
	char	x;
	char	y;
	char	z;

	a = '0';
	x = '0';
	y = '0';
	z = '0';
	loop_check(a, x, y, z);
}

void	loop_check(char a, char x, char y, char z)
{
	while (a <= '9')
	{
		x = '0';
		while (x <= '9')
		{
			y = a;
			while (y <= '9')
			{
				if (y == a)
					z = x + 1;
				else
					z = '0';
				while (z <= '9')
				{
					print_set(a, x, y, z);
					z++;
				}
				y++;
			}
			x++;
		}
		a++;
	}
}
