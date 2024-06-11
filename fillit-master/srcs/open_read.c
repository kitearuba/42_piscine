/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtrigalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 12:54:20 by dtrigalo          #+#    #+#             */
/*   Updated: 2019/04/23 13:30:38 by anleclab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_open_file(char *file)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	return (fd);
}

char	*ft_read_file(int fd)
{
	int		i;
	char	buff[F_BUFF_SIZE + 1];
	char	*str;

	if (!(i = read(fd, buff, F_BUFF_SIZE)))
		return (NULL);
	buff[i - 1] = '\0';
	if (!(str = ft_strnew(i)))
		return (NULL);
	ft_strcpy(str, buff);
	return (str);
}
