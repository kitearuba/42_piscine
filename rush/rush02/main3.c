#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 100

// Custom implementation of strchr()
char* custom_strchr(const char* s, int c) {
    while (*s != '\0') {
        if (*s == (char)c) {
            return (char*)s;
        }
        s++;
    }
    return NULL;
}

// Custom implementation of atoi()
int custom_atoi(const char* s) {
    int num = 0;
    int sign = 1;
    if (*s == '-') {
        sign = -1;
        s++;
    }
    while (*s >= '0' && *s <= '9') {
        num = num * 10 + (*s - '0');
        s++;
    }
    return num * sign;
}

int find_value_in_file(const char* filename, int target) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return -1;
    }

    char line[MAX_LINE_LENGTH];
    int found = 0;

    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        char* colon = custom_strchr(line, ':');
        if (colon) {
            *colon = '\0'; // Terminate the number part of the string
            int number = custom_atoi(line);
            if (number == target) {
                found = 1;
                printf("%s\n", colon + 2); // Skip ": " and print the name
                break;
            }
        }
    }

    fclose(file);
    return found;
}

int main(int argc, char *argv[]) {
    char* filename = "numbers.dict";
    if (argc == 2) {
        int found = find_value_in_file(filename, custom_atoi(argv[1]));
        if (!found) {
            printf("%d not found\n", custom_atoi(argv[1]));
        }
    } else {
        printf("Please provide a number as argument\n");
    }
    return 0;
}
