#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

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

int find_value_in_file(char* filename, int target) {
    int fd = open(filename, O_RDONLY);
    if (fd < 0) {
        perror("Error opening file");
        return -1;
    }

    char line[MAX_LINE_LENGTH];
    int found = 0;

    while (ft_fgets(line, MAX_LINE_LENGTH, fd) > 0) {
        char* colon = ft_strchr(line, ':');
        if (colon) {
            *colon = '\0';
            int number = ft_atoi(line);
            if (number == target) {
                found = 1;
                printf("%s", colon + 2);
                break;
            }
        }
    }

    close(fd);
    return found;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Please provide a number as argument\n");
        return 1;
    }

    char* filename = "numbers.dict";
    int found = find_value_in_file(filename, ft_atoi(argv[1]));
    if (!found) {
        printf("%d not found\n", ft_atoi(argv[1]));
    }

    return 0;
}
