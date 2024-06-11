/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main1542.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrossi-u <lrossi-u@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 17:51:22 by lrossi-u          #+#    #+#             */
/*   Updated: 2024/04/07 20:51:39 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

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
void ft_verify_number(char* filename, long long target) 
{
    if (target < 0) {
        // Handle negative numbers (if needed)
        // For simplicity, we'll ignore negative numbers in this context.
        return;
    } else if (target < 21 || (target < 100 && target % 10 == 0)) {
        // Directly find and print the name for numbers less than 21 and multiples of 10 up to 90
        find_value_in_file(filename, target);
    } else if (target < 100) {
        // For numbers 21-99 not a multiple of 10, print the tens place and then handle the units
        int tens = (target / 10) * 10;
        int units = target % 10;
        find_value_in_file(filename, tens);
        if (units) ft_verify_number(filename, units);
    } else {
        // For numbers 100 and beyond, find the most significant part and its magnitude
        long long place = 1;
        long long temp_target = target;
        while (temp_target >= 10) {
            temp_target /= 10;
            place *= 10;
        }
        
        long long leading_number = target / place;
        long long remainder = target % place;

        // Handle leading number
        if (leading_number > 1 || place == 100) {
            ft_verify_number(filename, leading_number);
        }
        find_value_in_file(filename, place);

        // Recursively handle the remainder of the number
        if (remainder) {
            ft_verify_number(filename, remainder);
        }
    }
}
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

void ft_verify_number(char* filename, long long target) 
{
    if (target < 0) {
        // Handle negative numbers (if needed)
        // For simplicity, we'll ignore negative numbers in this context.
        return;
    } else if (target < 21 || (target < 100 && target % 10 == 0)) {
        // Directly find and print the name for numbers less than 21 and multiples of 10 up to 90
        find_value_in_file(filename, target);
    } else if (target < 100) {
        // For numbers 21-99 not a multiple of 10, print the tens place and then handle the units
        int tens = (target / 10) * 10;
        int units = target % 10;
        find_value_in_file(filename, tens);
        if (units) ft_verify_number(filename, units);
    } else {
        // For numbers 100 and beyond, find the most significant part and its magnitude
        long long place = 1;
        long long temp_target = target;
        while (temp_target >= 10) {
            temp_target /= 10;
            place *= 10;
        }
        
        long long leading_number = target / place;
        long long remainder = target % place;

        // Handle leading number
        if (leading_number > 1 || place == 100) {
            ft_verify_number(filename, leading_number);
        }
        find_value_in_file(filename, place);

        // Recursively handle the remainder of the number
        if (remainder) {
            ft_verify_number(filename, remainder);
        }
    }
}

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
   /* if (found == 0) { 
		ft_putstr(error);
    }*/

    return 0;
}
