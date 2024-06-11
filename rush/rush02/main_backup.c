/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main1542.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrossi-u <lrossi-u@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 17:51:22 by lrossi-u          #+#    #+#             */
/*   Updated: 2024/04/07 21:19:29 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

#define MAX_LINE_LENGTH 100

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (&s[i]);
		i++;
	}
	return (NULL);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			str[i] = ' ';
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_atoi(char *s)
{
	int	num;
	int	sign;
	int	i;

	num = 0;
	sign = 1;
	i = 0;
	if (s[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		num = num * 10 + (s[i] - '0');
		i++;
	}
	return (num * sign);
}

ssize_t	ft_fgets(char *buf, int buf_size, int fd)
{
	int		i;
	ssize_t	result;

	i = 0;
	while (i < buf_size - 1)
	{
		result = read(fd, &buf[i], 1);
		if (result <= 0)
		{
			if (i == 0)
				return (result);
			break ;
		}
		if (buf[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	buf[i] = '\0';
	return (i);
}

int	find_value_in_file(char *filename, int target)
{
    char	*error;
    int		fd;
    char	line[MAX_LINE_LENGTH];
    int		found;
    char	*colon;
    int		number;

	error = "Error on reading file";
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr(error);
		return (-1);
	}
	found = 0;
	while (ft_fgets(line, MAX_LINE_LENGTH, fd) > 0)
	{
		colon = ft_strchr(line, ':');
		if (colon)
		{
			*colon = '\0';
			number = ft_atoi(line);
			if (number == target)
			{
				found = 1;
				ft_putstr(colon + 2);
				break ;
			}
		}
	}
	close(fd);
	return (found);
}

void ft_verify_number(char* filename, long long target) 
{
    if (target < 21){
        find_value_in_file(filename, target);
    } else if (target < 100) {
        int tens = target / 10 * 10;
        int units = target % 10;
        find_value_in_file(filename, tens);
        if (units > 0) {
            ft_verify_number(filename, units);
        }
    } else if (target < 1000) {
        int hundreds = target / 100;
        int remainder = target % 100;
		if (hundreds >= 1) ft_verify_number(filename, hundreds);
        find_value_in_file(filename, 100);
        if (remainder > 0) ft_verify_number(filename, remainder);
    } else {
        long long place = 1000;
        long long higher = target;
        while (higher / 1000 >= 1000) {
            place *= 1000;
            higher /= 1000;
        }
        long long leading = target / place;
        long long remainder = target % place;

        ft_verify_number(filename, leading);
        find_value_in_file(filename, place);

        if (remainder > 0) {
            if (remainder < 100) find_value_in_file(filename, 0); 
				ft_verify_number(filename, remainder);
       }
    }
}

int	main(int argc, char *argv[])
{
	char	*error;
	char	*filename;
	int		target;

	error = "Error on input";
	if (argc != 2)
	{
		ft_putstr(error);
		return (1);
	}
	filename = "numbers.dict";
	target = ft_atoi(argv[1]);
	ft_verify_number(filename, target);
	return (0);
}
/*
int main(int argc, char *argv[]) {
	char *error = "Error on input";
    if (argc != 2) {
		ft_putstr(error);
		return 1;
    }

    char* filename = "numbers.dict";
	int target = ft_atoi(argv[1]);
    //int found =
		ft_verify_number(filename, target);
    if (found == 0) {
		ft_putstr(error);
    }

    return 0;
}
*/
