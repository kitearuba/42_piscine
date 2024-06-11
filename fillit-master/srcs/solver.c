/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtrigalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 12:52:44 by dtrigalo          #+#    #+#             */
/*   Updated: 2019/04/23 13:20:05 by anleclab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	**initialize_sol(int sqsize)
{
	int		i;
	int		j;
	char	**sol;

	if (!(sol = (char **)malloc(sizeof(char *) * (sqsize + 1))))
		return (NULL);
	i = 0;
	while (i < sqsize)
	{
		if (!(sol[i] = (char *)malloc(sizeof(char) * (sqsize + 1))))
		{
			if (i > 0)
				while (--i >= 0)
					free(sol[i]);
			free(sol);
			return (NULL);
		}
		j = -1;
		while (++j < sqsize)
			sol[i][j] = '.';
		sol[i++][j] = 0;
	}
	sol[i] = NULL;
	return (sol);
}

static void	remove_ttmn(int ittmn, t_point **ttmns, char **sol, t_point pos)
{
	int		i;

	sol[pos.y][pos.x] = '.';
	i = 0;
	while (i < 3)
	{
		sol[pos.y + ttmns[ittmn][i].y][pos.x + ttmns[ittmn][i].x] = '.';
		i++;
	}
}

static int	place_ttmn(int ittmn, t_point **ttmns, char **sol, t_point pos)
{
	int		i;
	int		sqsize;
	t_point	coord;

	sqsize = ft_strlen(*sol);
	sol[pos.y][pos.x] = ittmn + 'A';
	i = 0;
	while (i < 3)
	{
		coord.x = pos.x + ttmns[ittmn][i].x;
		coord.y = pos.y + ttmns[ittmn][i].y;
		if (coord.x >= 0 && coord.x < sqsize && coord.y >= 0 && coord.y < sqsize
				&& sol[coord.y][coord.x] == '.')
			sol[coord.y][coord.x] = ittmn + 'A';
		else
		{
			while (--i >= 0)
				sol[pos.y + ttmns[ittmn][i].y][pos.x + ttmns[ittmn][i].x] = '.';
			sol[pos.y][pos.x] = '.';
			return (0);
		}
		i++;
	}
	return (1);
}

static int	fillit(int ittmn, t_point **ttmns, char **sol, int sqsize)
{
	t_point	i;

	if (!ttmns[ittmn])
		return (1);
	i.y = -1;
	while (++i.y < sqsize)
	{
		i.x = -1;
		while (++i.x < sqsize)
		{
			if (sol[i.y][i.x] == '.')
				if (place_ttmn(ittmn, ttmns, sol, i))
				{
					if (fillit(ittmn + 1, ttmns, sol, sqsize))
						return (1);
					remove_ttmn(ittmn, ttmns, sol, i);
				}
		}
	}
	return (0);
}

char		**solver(int nbttmns, t_point **ttmns)
{
	int		i;
	int		sqsize;
	int		solved;
	char	**sol;

	sqsize = uproundsqrt(4 * nbttmns);
	solved = 0;
	while (!solved)
	{
		if (!(sol = initialize_sol(sqsize)))
			return (NULL);
		solved = fillit(0, ttmns, sol, sqsize);
		if (!solved)
		{
			i = 0;
			while (i < sqsize)
			{
				free(sol[i]);
				i++;
			}
			free(sol);
			sqsize++;
		}
	}
	return (sol);
}
