/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtrigalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 12:54:27 by dtrigalo          #+#    #+#             */
/*   Updated: 2019/04/23 13:33:24 by anleclab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	end_program_final(char *tet, t_point **ttmns, int tet_nbr,
		int success)
{
	int		i;

	free(tet);
	i = -1;
	while (++i <= tet_nbr)
		free(ttmns[i]);
	free(ttmns);
	if (!success)
		ft_putstr("error\n");
	exit(0);
}

static void	end_program_err_arg(void)
{
	ft_putstr("usage: ./fillit test_file\n");
	exit(0);
}

static void	end_program_err_fd_file(void)
{
	ft_putstr("error\n");
	exit(0);
}

static void	end_program_err_ttmns(char *tet)
{
	free(tet);
	ft_putstr("error\n");
	exit(0);
}

int			main(int ac, char **av)
{
	char	*tet;
	char	**solution;
	t_point	**ttmns;

	tet = NULL;
	solution = NULL;
	ttmns = NULL;
	if (ac != 2)
		end_program_err_arg();
	if ((ac = ft_open_file(av[1])) == -1
			|| !(tet = ft_read_file(ac)) ||
			(ac = (ft_strlen(tet) + 2) / 21) > 26)
		end_program_err_fd_file();
	if (!(check_legal_test_file(tet, ac)) || !(ttmns = get_tet(tet, ac)))
		end_program_err_ttmns(tet);
	if (!(solution = solver(ac, ttmns)))
		end_program_final(tet, ttmns, ac, 0);
	print_map(solution);
	end_program_final(tet, ttmns, ac, 1);
	return (0);
}
