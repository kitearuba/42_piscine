/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_legal_test_file.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtrigalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 12:53:14 by dtrigalo          #+#    #+#             */
/*   Updated: 2019/04/23 13:18:58 by anleclab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	last_tet(char *str, int i)
{
	int		row;
	int		col;
	int		j;

	j = -1;
	while (++j < 19 && str[i + j])
		if (str[i + j] != '.' && str[i + j] != '#' && str[i + j] != '\n')
			return (0);
	if (j != 19 || str[i + j])
		return (0);
	row = -1;
	while (++row < 4)
	{
		col = -1;
		while (str[i] != '\n' && str[i] != '\0')
		{
			i++;
			col++;
		}
		if (col != 3)
			return (0);
		i++;
	}
	return (1);
}

int			check_legal_test_file(char *str, int tet_nbr)
{
	int			row;
	int			col;
	long long	i;

	i = 0;
	while (tet_nbr-- != 1 && str[i])
	{
		row = -1;
		while (++row < 4)
		{
			col = -1;
			while (str[i] != '\n' && str[i] != 0)
			{
				if (str[i] != '.' && str[i] != '#')
					return (0);
				col++;
				i++;
			}
			if (++i && col != 3)
				return (0);
		}
		if (str[i++] != '\n')
			return (0);
	}
	return (last_tet(str, i));
}
