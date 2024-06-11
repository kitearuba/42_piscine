//
// Created by christian on 29/03/24.
//
#include <unistd.h>

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return i; // Return the length, not the character at the end of the string
}

int main(void)
{
    // Define a proper C string with a null terminator
    char x[] = "1234"; // Example string
    // Get the length of the string
    int len = ft_strlen(x);
    // Convert the length to a string to print it
    char lenStr[10]; // Large enough to hold any int value
    int lenOfLen = sprintf(lenStr, "%d", len); // Convert length to string
    // Write the length as a string to stdout
    write(1, lenStr, lenOfLen);
    return 0;
}
