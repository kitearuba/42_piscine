/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:22:14 by chrrodri          #+#    #+#             */
/*   Updated: 2024/04/10 15:15:03 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2);

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		write (2, "Error: No arguments were provided!\n", 35);
		return (1);
	}
	if (argv >= 2)
	{
		char	[]s1;
		char	[]s2;
		char	result;
		
		s1 = argv[0];
		s2 = argv[1];
		result = ft_strcmp(s1, s2);
		write (2, result, 1);
	}
	return (0);
}

int ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && (s1[i] != '\0' || s2[i] != '\0'))
		++i;
	return (s1[i] - s2[i]);	
}
