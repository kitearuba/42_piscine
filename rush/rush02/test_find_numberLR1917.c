/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_find_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 13:22:44 by chrrodri          #+#    #+#             */
/*   Updated: 2024/04/06 19:16:54 by lrossi-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

#define MAX_LINE_LENGTH 100

char*	ft_strchr(char* str, char c) {
    while (*str != '\0') 
	{
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
	int i = 0;
	int j = 0;
	char* word = NULL;	
    while ( (bytes_read = read(file, line, MAX_LINE_LENGTH) ) > 0)
	{
		int number = atoi(line);
        char* colon = ft_strchr(line, '\n');
		char* skipLine = ft_strchr(line, '\n');
		if (colon)
		{
			printf("00");
            *colon = '\0';
			if (number == target)
			{
				printf("11");
				found = 1;
            }
		}
		if (skipLine)
		{
					printf("22");
					printf("33 %d == %d", number, target);
			if (number == target)
			{
					printf("44 %d == %d", number, target);
				while (skipLine[i] != ' ' || skipLine[i] != '\0')
				{
					i++;
				}
				while (skipLine[i] != '\0')
				{
					printf("OO");
					word[j] = skipLine[i];
					i++;
					write(1, &word[j], 1);
					j++;
				}
                break;
            }
        }
    }
    close(file);
    return found;
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' )
	{
		write(1, &str[i], 1);
		i++;
	}
}

//Function being created
/*
char	*ft_print(int target, int number)
{
	int i = 0;
	if (target <= 20)
	{
		while (target != number)
		{
			i++;
			if (target == number)
			{

}
*/
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
