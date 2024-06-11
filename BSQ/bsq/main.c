/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:30:27 by chrrodri          #+#    #+#             */
/*   Updated: 2024/04/10 18:49:19 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_fd(char *str, int fd);

int		ft_atoi(char *str);

void	ft_process_file(int fd);

int	main(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
	{
		write (2, "Error: No arguments were provided!\n", 35);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error: Cannot open file.\n", 2);
		return (1);
	}
	ft_process_file(fd);
	close(fd);
	return (0);
}
