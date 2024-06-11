/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 13:22:44 by chrrodri          #+#    #+#             */
/*   Updated: 2024/04/06 17:11:02 by chrrodri         ###   ########.fr       */
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
        char* colon = ft_strchr(line, ':');
        if (colon) {
            *colon = '\0';
            int number = atoi(line); 
			if (number == target) 
			{
                found = 1;
                break;
            }
        }
    }
    close(file);
    return found;
}

int main(void) {
    int target = 3;
    char* filename = "numbers.dict";

    int found = find_value_in_file(filename, target);
    if (found) {
        printf("%d found\n", target);
    } else {
        printf(" %d not found\n", target);
    }

    return 0;
}

