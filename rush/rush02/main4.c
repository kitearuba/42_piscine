#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

// Assuming custom_atoi and custom_strchr are defined as before

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

// Reads a line from the file descriptor into the provided buffer
// Returns the number of bytes read, or -1 on error/end of file
ssize_t read_line(int fd, char *buffer, size_t max_length) {
    ssize_t total_read = 0;
    char ch;
    while (read(fd, &ch, 1) > 0 && (size_t)total_read < max_length - 1) {
        buffer[total_read++] = ch;
        if (ch == '\n') break;
    }
    buffer[total_read] = '\0'; // Null-terminate the string
    return total_read > 0 ? total_read : -1;
}

// Function to find the text for a given number in the dictionary
char *find_text_for_number(const char* filename, int target_number) {
    static char text[MAX_LINE_LENGTH]; // Buffer to store the found text
    int fd = open(filename, O_RDONLY);
    if (fd < 0) {
        perror("Error opening file");
        return NULL;
    }

    char line[MAX_LINE_LENGTH];
    while (read_line(fd, line, sizeof(line)) > 0) {
        char *colon_pos = custom_strchr(line, ':');
        if (!colon_pos) continue; // Skip if line does not contain ':'

        *colon_pos = '\0'; // Temporarily terminate the string at the colon
        int number = custom_atoi(line);
        if (number == target_number) {
            // Copy the name part into text, skipping ": " (2 characters)
            for (int i = 0; colon_pos + 2 + i < line + MAX_LINE_LENGTH && colon_pos[2 + i] != '\0'; i++) {
                text[i] = colon_pos[2 + i];
                text[i + 1] = '\0'; // Ensure null-termination
            }

            close(fd);
            return text;
        }
    }

    close(fd);
    return NULL; // Number not found
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <number>\n", argv[0]);
        return 1;
    }

    int number = custom_atoi(argv[1]);
    char* filename = "numbers.dict";
    char* text = find_text_for_number(filename, number);
    if (text) {
        printf("%d: %s\n", number, text);
    } else {
        printf("%d not found\n", number);
    }

    return 0;
}
