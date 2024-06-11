/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrossi-u <lrossi-u@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 10:31:46 by lrossi-u          #+#    #+#             */
/*   Updated: 2024/04/06 16:44:01 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int	ft_pen(char *fileName)
{
	int pt = open(fileName, O_RDONLY);

	if (pt == -1)
	{
		printf("Error");
		return(1);
	}
	char buffer[1024];

    int bytesRead = read(pt, buffer, sizeof(buffer));

    printf("%d bytes read!\n", bytesRead);
    printf("File Contents: %s\n", buffer);
	return (bytesRead);
}

int main(void)
{
	char *file = "numbers.dict";
	ft_pen(file);
	return (0);
}
