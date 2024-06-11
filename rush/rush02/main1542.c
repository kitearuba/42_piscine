/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main1542.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrossi-u <lrossi-u@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 17:51:22 by lrossi-u          #+#    #+#             */
/*   Updated: 2024/04/07 18:45:06 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

#define MAX_LINE_LENGTH 100

char* ft_strchr(char *s, int c) {
   int i;
   
   i = 0;
   while (s[i] != '\0') 
   {
       if (s[i] == c)
           return (&s[i]);
       i++;
   }
   return NULL;
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' )
	{
		if (str[i] == '\n')
			str[i] = ' ';
		write(1, &str[i], 1);
		i++;
	}
}

int ft_atoi(char *s) {
    int num;
    int sign;
    int i;

    num = 0;
    sign = 1;
    i = 0;
    if (s[i] == '-') {
        sign = -1;
        i++;
    }
    while (s[i] >= '0' && s[i] <= '9') {
        num = num * 10 + (s[i] - '0');
        i++;
    }
    return (num * sign);
}

ssize_t ft_fgets(char* buf, int buf_size, int fd) {
    int i;
   
    i = 0;
    while (i < buf_size - 1) {
        ssize_t result = read(fd, &buf[i], 1);
        if (result <= 0) { // End of file or error
            if (i == 0) return result; // No data read
            break;
        }
        if (buf[i] == '\n') { // read new line
            i++;
            break;
        }
        i++;
    }
    buf[i] = '\0'; 
    return i; // i = number of bytes read
}



int find_value_in_file(char* filename, int target) 	
{
	char *error = "Error on reading file";
    int fd = open(filename, O_RDONLY);
    if (fd < 0) 
	{
        ft_putstr(error);
        return -1;
    }
    char line[MAX_LINE_LENGTH];
    int found = 0;

    while (ft_fgets(line, MAX_LINE_LENGTH, fd) > 0) {
        char* colon = ft_strchr(line, ':');
        if (colon) {
            *colon = '\0';
            int number = ft_atoi(line);
            if (number == target) {
                found = 1;
				ft_putstr(colon + 2);
                break;
            }
        }
    }

    close(fd);
    return found;
}

int	ft_verify_number(char* filename, int target)
{
	int n1 = 0;
	int n2 = 0;
	int n3 = 0;
	int result = 0;
	if (target < 21)
	{
		find_value_in_file(filename, target);
	}
	else if (target > 20 && target < 100)
	{
		n1 = target / 10;
		n2 = target % 10;
		find_value_in_file(filename, n1 * 10);
		if (n2 != 0)
			find_value_in_file(filename, n2);
	}
	else if (target > 99 && target <= 1000)
	{
		n1 = target / 100;
		n2 = n1 / 100;
		n3 = target % 100;
		find_value_in_file(filename, n1);
		find_value_in_file(filename, 100);
		ft_verify_number(filename, n3);
	}
	else if (target > 999  && target < 10000)
	{
		n1 = target / 1000;
		n2 = n1 / 1000;
		n3 = target % 1000;
		find_value_in_file(filename, n1);
		find_value_in_file(filename, 1000);
		ft_verify_number(filename, n3);
	}
	else if (target > 9999  && target < 21000)
	{
		n1 = target / 1000;
		n2 = target / 1000;
		n3 = target % 1000;
		find_value_in_file(filename, n1);
		find_value_in_file(filename, 1000);
		ft_verify_number(filename, n3);
	}
	result = (n1 * 10) + n2;
	return (result);
}

int main(int argc, char *argv[]) {
	char *error = "Error on input";
    if (argc != 2) {
		ft_putstr(error);
		return 1;
    }

    char* filename = "numbers.dict";
	int target = ft_atoi(argv[1]);
    int found = ft_verify_number(filename, target);
    if (found == 0) { 
		ft_putstr(error);
    }

    return 0;
}
