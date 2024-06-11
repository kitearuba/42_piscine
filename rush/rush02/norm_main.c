#include <unistd.h>
#include <fcntl.h>

#define MAX_LINE_LENGTH 100

char *ft_strchr(char *s, int c)
{
    int i;

    i = 0;
    while (s[i] != '\0')
    {
        if (s[i] == c)
            return (&s[i]);
        i++;
    }
    return (NULL);
}

void ft_putstr(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == '\n')
            str[i] = ' ';
        write(1, &str[i], 1);
        i++;
    }
}

int ft_atoi(char *s)
{
    int num;
    int sign;
    int i;

    num = 0;
    sign = 1;
    i = 0;
    if (s[i] == '-')
    {
        sign = -1;
        i++;
    }
    while (s[i] >= '0' && s[i] <= '9')
    {
        num = num * 10 + (s[i] - '0');
        i++;
    }
    return (num * sign);
}

ssize_t ft_fgets(char *buf, int buf_size, int fd)
{
    int i;
    ssize_t result;

    i = 0;
    while (i < buf_size - 1)
    {
        result = read(fd, &buf[i], 1);
        if (result <= 0)
        {
            if (i == 0)
                return (result);
            break;
        }
        if (buf[i] == '\n')
        {
            i++;
            break;
        }
        i++;
    }
    buf[i] = '\0';
    return (i);
}

int find_value_in_file(char *filename, int target)
{
    char *error = "Error on reading file";
    int fd;
    char line[MAX_LINE_LENGTH];
    int found;
    char *colon;
    int number;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        ft_putstr(error);
        return (-1);
    }
    found = 0;
    while (ft_fgets(line, MAX_LINE_LENGTH, fd) > 0)
    {
        colon = ft_strchr(line, ':');
        if (colon)
        {
            *colon = '\0';
            number = ft_atoi(line);
            if (number == target)
            {
                found = 1;
                ft_putstr(colon + 2);
                break;
            }
        }
    }
    close(fd);
    return (found);
}

// The ft_verify_number function and its recursive logic must be split or revised 
// to fit within the Norminette rules, particularly the 25-line limit per function.
// Consider breaking down the logic into smaller helper functions if necessary.

int main(int argc, char *argv[])
{
    char *error = "Error on input";
    char *filename;
    int target;

    if (argc != 2)
    {
        ft_putstr(error);
        return (1);
    }
    filename = "numbers.dict";
    target = ft_atoi(argv[1]);
    ft_verify_number(filename, target);
    return (0);
}