/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 13:22:44 by chrrodri          #+#    #+#             */
/*   Updated: 2024/04/06 17:10:31 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

#define MAX_LINE_LENGTH 100

int find_value_in_file(const char* filename, int target) {
    FILE* file = fopen(filename, "r");
    if (!file) 
	{
        perror("Error opening file");
        return -1;
	}

    char line[MAX_LINE_LENGTH];
    int found = 0;

    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        char* colon = strchr(line, ':');
        if (colon) {
            *colon = '\0';
            int number = atoi(line); 
            if (number == target) {
                found = 1;
                break;
            }
        }
    }

    fclose(file);
    return found;
}
You can use this function to search for a number in your text file. For example:int main() {
    int target = 20;
	const char* filename = "numbers.dict";

    int found = find_value_in_file(filename, target);
    if (found) {
        printf("%d found\n", target);
    } else {
        printf("%d not found\n", target);
    }

    return 0;
}

