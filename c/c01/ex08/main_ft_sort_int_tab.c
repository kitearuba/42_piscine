/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:42:56 by chrrodri          #+#    #+#             */
/*   Updated: 2024/04/04 10:01:49 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_sort_int_tab(int *tab, int size);

void	ft_swap(int *a, int *b);

void	ft_putnbr(int num);

void	ft_putchar(char c);

int	main(void)
{
	int arr[] = {33, 2, -43, 1, 2232, 4, 0};
	int size = sizeof(arr) / sizeof(arr[0]);
	int *tab = arr;
	int i = 0;
	ft_sort_int_tab(tab, size);
	while (i < size)
	{
		ft_putnbr(arr[i]);
		ft_putchar(' ');
		i++;
	}
	return (0);
}

void ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int j;
	
	i = 0;
	j = 0;
	while (i < size - i - 1)
	{
		j = 0;
		while (j < size - j -1)
		{
			if (tab[j] > tab[j + 1])
				ft_swap(&tab[j], &tab[j + 1]);
			j++;
		}
		i++;
	}
}

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_putnbr(int num)
{
	if (num < 0)
	{
		ft_putchar('-');
		num = -num;
	}
	if (num > 9)
		ft_putnbr(num / 10);
	ft_putchar(num % 10 + '0');
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
