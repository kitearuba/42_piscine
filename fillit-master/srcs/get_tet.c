/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tet.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtrigalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 14:03:19 by dtrigalo          #+#    #+#             */
/*   Updated: 2019/04/23 13:19:21 by anleclab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		get_tet_coords(t_point *ttmn, char *str)
{
	t_point	i;
	t_point topleftmost;
	int		found_tet_part;

	i.y = -1;
	found_tet_part = 0;
	while (++i.y < 4 && (i.x = -1))
		while (++i.x < 4)
		{
			if (!found_tet_part && str[5 * i.y + i.x] == '#')
			{
				found_tet_part++;
				topleftmost.x = i.x;
				topleftmost.y = i.y;
			}
			else if (str[5 * i.y + i.x] == '#' && found_tet_part <= 3)
			{
				(ttmn + found_tet_part - 1)->x = i.x - topleftmost.x;
				(ttmn + found_tet_part - 1)->y = i.y - topleftmost.y;
				found_tet_part++;
			}
			else if (str[5 * i.y + i.x] == '#' && found_tet_part == 4)
				return (0);
		}
	return (found_tet_part < 4 ? 0 : 1);
}

static t_point	ctc_aux(t_point *ttmn, int i, int j)
{
	t_point dif;

	dif.x = ttmn[i].x - ttmn[j].x;
	dif.x = (dif.x < 0 ? -dif.x : dif.x);
	dif.y = ttmn[i].y - ttmn[j++].y;
	dif.y = (dif.y < 0 ? -dif.y : dif.y);
	return (dif);
}

static int		check_tet_coords(t_point *ttmn)
{
	int		contact_nbr;
	int		i;
	int		j;
	t_point	dif;

	contact_nbr = 0;
	i = -1;
	while (++i < 3)
	{
		if (((ttmn[i].x == 1 || ttmn[i].x == -1) && ttmn[i].y == 0)
				|| (ttmn[i].x == 0 && (ttmn[i].y == 1 || ttmn[i].y == -1)))
			contact_nbr++;
	}
	i = -1;
	while ((i + 1) < 2)
	{
		j = ++i + 1;
		while (j < 3)
		{
			dif = ctc_aux(ttmn, i, j++);
			if ((dif.x == 0 && dif.y == 1) || (dif.x == 1 && dif.y == 0))
				contact_nbr++;
		}
	}
	return ((contact_nbr >= 3 ? 1 : 0));
}

static t_point	**initialize_ttmns(int tet_nbr)
{
	int		i;
	t_point **ttmns;

	if (!(ttmns = (t_point **)malloc(sizeof(t_point *) * (tet_nbr + 1))))
		return (NULL);
	ttmns[tet_nbr] = NULL;
	i = 0;
	while (i < tet_nbr)
	{
		if (!(ttmns[i] = (t_point *)malloc(sizeof(t_point) * 3)))
		{
			i--;
			while (i >= 0)
			{
				free(ttmns[i]);
				i--;
			}
			free(ttmns);
			return (NULL);
		}
		i++;
	}
	return (ttmns);
}

t_point			**get_tet(char *tet, int tet_nbr)
{
	int		i;
	t_point	**ttmns;

	if (!(ttmns = initialize_ttmns(tet_nbr)))
		return (NULL);
	i = 0;
	while (i < tet_nbr)
	{
		if (!(get_tet_coords(ttmns[i], tet + i * 21))
				|| !(check_tet_coords(ttmns[i])))
		{
			while (tet_nbr >= 0)
			{
				free(ttmns[tet_nbr]);
				tet_nbr--;
			}
			free(ttmns);
			return (NULL);
		}
		i++;
	}
	return (ttmns);
}
