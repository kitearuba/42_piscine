/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anleclab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 10:44:49 by anleclab          #+#    #+#             */
/*   Updated: 2018/11/06 10:55:39 by anleclab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_count_if(char **tab, int (*f)(char*))
{
	int		res;
	int		i;

	res = 0;
	i = 0;
	while (tab[i])
	{
		if (f(tab[i]) == 1)
			res++;
		i++;
	}
	return (res);
}
