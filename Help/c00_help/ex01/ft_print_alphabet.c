/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:35:26 by chrrodri          #+#    #+#             */
/*   Updated: 2024/03/21 19:13:22 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	print_alphabet(void);

int	main(void)
{
	print_alphabet();
	return (0);
}

void	print_alphabet(void)
{
	char	letter;
	char	space;

	letter = 'a';
	space = '\n';
	while (letter <= 'z')
	{
		write(1, &letter, 1);
		letter++;
	}
	write(1, &space, 1);
}
