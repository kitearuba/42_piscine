/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:39:27 by chrrodri          #+#    #+#             */
/*   Updated: 2024/03/21 19:22:18 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

int	mainvoid(void)
{
	char	c;

	c = '0';
	while (c < '9')
	{
		ft_putchar(c);
		c++;
	}
	return (0);
}

void	ft_putchar(char c)
{
	write (1, &c, 1);
}
