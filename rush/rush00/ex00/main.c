/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:08:01 by chrrodri          #+#    #+#             */
/*   Updated: 2024/03/26 17:10:29 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rush(int x, int y);
int	ft_atoi(const char *nptr);

int	main(int argc, char **argv)
{
    int	x;
    int	y;

    if (argc != 3)
    {
        write(2, "Error: Please provide exactly 2 arguments.\n", 43);
        return (1);
    }
    x = ft_atoi(argv[1]);
    y = ft_atoi(argv[2]);
    if (x <= 0 || y <= 0)
    {
        write(2, "Error: Arguments must be positive integers.\n", 44);
        return (1);
    }
    rush(x, y);
    return (0);
}