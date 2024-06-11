/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 13:28:34 by chrrodri          #+#    #+#             */
/*   Updated: 2024/03/24 18:50:47 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	line_print(int width, char pos1, char pos_mid, char pos_last);

void	rush(int x, int y)
{
	int	line;

	line = 1;
	if (x < 1 || y < 1)
	{
		write (2, "ERROR! PLEASE INTRODUCE A VALID VALUE!\n", 39);
		return ;
	}
	if (x >= 1 && y >= 1)
	{
		while (line <= y)
		{
			if (line == 1)
				line_print (x, 'A', 'B', 'A');
			else if (line == y)
				line_print (x, 'C', 'B', 'C');
			else
				line_print (x, 'B', ' ', 'B');
			line++;
		}
	}
}

void	line_print(int width, char pos1, char pos_mid, char pos_last)
{
	int	column_pos;

	column_pos = 1;
	while (column_pos <= width)
	{
		if (column_pos == 1)
			ft_putchar (pos1);
		else if (column_pos == width)
			ft_putchar (pos_last);
		else
			ft_putchar (pos_mid);
		column_pos++;
	}
	ft_putchar ('\n');
}
