/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anleclab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 12:48:51 by anleclab          #+#    #+#             */
/*   Updated: 2018/11/06 13:01:03 by anleclab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define BUFF_SIZE 30

void	ft_display_file(int fd)
{
	int		nreadchar;
	char	buf[BUFF_SIZE + 1];

	nreadchar = 1;
	while (nreadchar && nreadchar != -1)
	{
		nreadchar = read(fd, buf, BUFF_SIZE);
		if (nreadchar == -1)
		{
			buf[0] = 0;
			write(2, "read() failed.\n", 15);
		}
		else
		{
			buf[nreadchar] = 0;
			write(1, buf, nreadchar);
		}
	}
}

int		main(int argc, char **argv)
{
	int		fd;

	if (argc == 1)
	{
		write(2, "File name missing.\n", 19);
		return (1);
	}
	if (argc > 2)
	{
		write(2, "Too many arguments.\n", 20);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		write(2, "open() failed.\n", 15);
		return (1);
	}
	ft_display_file(fd);
	if (close(fd) == -1)
	{
		write(2, "close() failed.\n", 16);
		return (1);
	}
	return (0);
}
