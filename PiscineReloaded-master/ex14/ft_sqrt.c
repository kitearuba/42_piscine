/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anleclab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 16:24:34 by anleclab          #+#    #+#             */
/*   Updated: 2018/11/05 16:48:08 by anleclab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int		res;

	res = 0;
	while (res < nb / 2)
	{
		if (res * res == nb)
			return (res);
		else
			res++;
	}
	if (res == nb / 2)
	{
		if (res * res == nb)
			return (res);
		else
			return (0);
	}
	return (res);
}
