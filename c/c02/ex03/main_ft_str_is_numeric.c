/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:29:11 by chrrodri          #+#    #+#             */
/*   Updated: 2024/04/09 17:04:53 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int	ft_str_is_numeric(char *str);

void	ft_putstr(char *str);

int	main(int argc, char **argv)
{
	char *str;
	int	x;

	if (argc < 3)
	{
        	ft_putstr("Usage: ");
        	ft_putstr(argv[0]);
        	ft_putstr(" <source string> <number of characters to copy>\n");
        	return 1;
    	}
	str = argv[2];
	x = ft_str_is_numeric(str);
	ft_putchar(48 + x);
	ft_putchar('\n');
	return (0);
}

int ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] > 47 &&  str[i] < 58)
			i++;
		else
			return (0);
	}
	return (1);
}

void	ft_putchar(char c)
{
	write (1, &c, 1);
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
