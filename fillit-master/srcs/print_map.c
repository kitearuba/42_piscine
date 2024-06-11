/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtrigalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 12:54:14 by dtrigalo          #+#    #+#             */
/*   Updated: 2019/04/23 13:20:00 by anleclab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		free_map(char **map)
{
	int		i;
	int		len;

	i = -1;
	len = ft_strlen(map[0]);
	while (++i <= len)
		free(map[i]);
	free(map);
}

void			print_map(char **map)
{
	int		i;

	i = -1;
	while (map[++i])
	{
		ft_putstr(map[i]);
		ft_putchar('\n');
	}
	free_map(map);
}
