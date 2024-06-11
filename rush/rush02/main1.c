/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 13:22:44 by chrrodri          #+#    #+#             */
/*   Updated: 2024/04/06 15:30:41 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 100

int find_value_in_file(const char* filename, int target) {
    FILE* file = fopen(filename, "r");
   if (!file) {
        perror("Error opening file");
        return -1; // Return -1 to indicate an error
    }

    char line[MAX_LINE_LENGTH];
	int found = 0;

    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        // Splitting the line using the ":" delimiter
        char* colon = strchr(line, ':');
        if (colon) {
            *colon = '\0';
            int number = atoi(line); // Convert the string to an integer
            if (number == target) {
                found = 1;
                break;
            }
        }
    }

    fclose(file);
    return found;
}

int main() {
    int target = 4; // The number you want to search for
    char* filename = "numbers.dict"; // Your text file name

    int found = find_value_in_file(filename, target);
    if (found) {
        printf("%d found in the file.\n", target);
    } else {
        printf(" %d not found in the file.\n", target);
    }

    return 0;
}
