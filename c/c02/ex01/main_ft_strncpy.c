/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 12:56:27 by chrrodri          #+#    #+#             */
/*   Updated: 2024/04/08 22:26:26 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n);

void	ft_putchar(char c);

void	ft_putstr(char *str);

int	ft_atoi(char *str);

int	main(int argc, char **argv)
{
	int	n;

	if (argc < 3)
	{
        	ft_putstr("Usage: ");
        	ft_putstr(argv[0]);
        	ft_putstr(" <source string> <number of characters to copy>\n");
        	return 1;
    	}
    	n = ft_atoi(argv[2]);
    	char dest[100];
    	ft_strncpy(dest, argv[1], n);
	dest[n] = '\0';
	ft_putstr("Copied string: ");
	ft_putstr(dest);
	ft_putchar('\n');
	return (0);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		++i;
	}
}

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int ft_atoi(char *str)
{
	int	result;
	int	i;

	result = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
		{
			ft_putstr( "Error");
			break ;
		}
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}
