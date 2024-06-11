/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_find_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 13:22:44 by chrrodri          #+#    #+#             */
/*   Updated: 2024/04/06 19:35:03 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

#define MAX_LINE_LENGTH 100

char*	ft_strchr(char* str, char c) {
    while (*str != '\0') {
        if (*str == c) {
            return (char*) str;
        }
        str++;
    }
    if (c == '\0') {
        return (char*)str;
    }
    return NULL;
}

int	find_value_in_file(char* filename, int target) {
    int file = open(filename, O_RDONLY);
    if (file == -1) {
        perror("Error opening file");
        return (-1);
    }

    char line[MAX_LINE_LENGTH];
    int found = 0;

    ssize_t bytes_read;
    while ((bytes_read = read(file, line, MAX_LINE_LENGTH)) > 0) {
        char *full_line = ft_strchr(line, ' ');
		int	i;
		i = 0;
		while (full_line[i] != '\n')
		{
			write(1, &full_line[i], 1);
			i++;
		}
        char* colon = ft_strchr(line, ':');
        if (colon) {
            *colon = '\0';
            int number = atoi(line); 
			if (number == target) 
			{
				printf("Value of number: %d\n", number);
				printf("Value of line: %s\n", full_line);
                found = 1;
                break;
            }
        }
    }
    close(file);
    return found;
}

int main(int arc, char *arv[]) 
{
	char* filename = "numbers.dict";
	if (arc == 2)
	{
		int found = find_value_in_file(filename, atoi(arv[1]));
    	if (found) 
        	printf("%d found\n", atoi(arv[1])); 
		else 
       		printf("%d not found\n", atoi(arv[1]));
	}
	else
		printf("Please, put enough characters");
    return 0;
}
