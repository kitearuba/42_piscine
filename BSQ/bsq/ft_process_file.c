/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:28:55 by chrrodri          #+#    #+#             */
/*   Updated: 2024/04/10 18:49:34 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_process_file(int fd)
{
	char	buffer[1];
	int		lines;
	char	info[4];
	int		info_index;
	char	empty_char;

	lines = 0;
	info_index = 0;
	while (read(fd, buffer, 1) && buffer[0] != '\n')
	{
		if (info_index < 3 || (info_index == 3 && buffer[0] >= '0'
				&& buffer[0] <= '9'))
			info[info_index++] = buffer[0];
	}
	if (info_index < 4)
	{
		ft_putstr_fd("Error: File format invalid.\n", 2);
		return ;
	}
	lines = ft_atoi(info);
	empty_char = info[1];
	obstacle_char = info[2];
	full_char = info[3];
}
