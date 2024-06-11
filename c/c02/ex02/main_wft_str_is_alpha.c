/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:15:04 by chrrodri          #+#    #+#             */
/*   Updated: 2024/04/09 16:00:29 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (( str[i] >= 'A' && str[i] <= 'Z') 
		|| (str[i] >= 'a' && str[i] <= 'z'))
		{
			return (1);
			i++;
		}
		else
			return (0);
	}
	return (0);
}
