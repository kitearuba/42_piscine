#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

#define MAX_LINE_LENGTH 100

char* ft_strchr(char* str, char c) {
    while (*str != '\0') {
        if (*str == c) {
            return str;
        }
        str++;
    }
    if (c == '\0') {
        return str;
    }
    return NULL;
}

char* my_strtok(char* str, const char* delim) {
    static char* token = NULL;
    if (str != NULL) {
        token = str;
    } else if (token == NULL) {
        return NULL;
    }

    char* ptr = token;
    while (*ptr != '\0') {
        const char* d = delim;
        while (*d != '\0') {
            if (*ptr == *d) {
                *ptr = '\0';
                token = ptr + 1;
                return ptr;
            }
            d++;
        }
        ptr++;
    }

    if (*token == '\0') {
        return NULL;
    }

    char* ret = token;
    token = NULL;
    return ret;
}

int find_value_in_file(char* filename, int target) {
    int file = open(filename, O_RDONLY);
    if (file == -1) {
        perror("Error opening file");
        return (-1);
    }

    char line[MAX_LINE_LENGTH];
    int found = 0;

    ssize_t bytes_read;
    while ((bytes_read = read(file, line, MAX_LINE_LENGTH)) > 0) {
        char *full_line = line;
        int i = 0;
        while (line[i] != '\n') {
            i++;
            if (i == bytes_read) { // Check if reached end of buffer
                bytes_read = read(file, line + i, MAX_LINE_LENGTH - i);
                if (bytes_read <= 0) {
                    break; // End of file or error
                }
            }
        }
        line[i] = '\0'; // Null-terminate the line

        // Tokenize the line by ":"
        char* token = my_strtok(full_line, ":");
        if (token) {
            int number = atoi(token);
            // Check if the number matches the target
            if (number == target) {
                // Print the corresponding line
                token = my_strtok(NULL, ":");
                if (token) {
                    printf("Value of number: %d\n", number);
                    printf("Value of line: %s\n", token + 1); // Skip the space after ':'
                    found = 1;
                    break;
                }
            }
        }
    }
    close(file);
    return found;
}

int main(int argc, char *argv[]) {
    char* filename = "numbers.dict";
    if (argc == 2) {
        int found = find_value_in_file(filename, atoi(argv[1]));
        if (found) {
            printf("%d found\n", atoi(argv[1])); 
        } else {
            printf("%d not found\n", atoi(argv[1]));
        }
    } else {
        printf("Please provide a number as argument\n");
    }
    return 0;
}
