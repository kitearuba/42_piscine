#include "ft_putchar.h"

// Function prototypes
void    ft_print_error(void);
void    ft_initialize(char *str, int *attr, int arr[4][4]);
int     ft_input_to_arr(char *str, int *attr, int arr[4][4]);
void    ft_solve(int arr[4][4]); // Ensure you define this function elsewhere

int     main(int argc, char **argv)
{
    int arr[4][4] = {{0}};
    int attr[3] = {0, 0, 0};

    if (argc != 2)
    {
        ft_print_error();
        return (0);
    }
    if (ft_input_to_arr(argv[1], attr, arr))
        return (0);
    ft_solve(arr);
    return (0);
}

void    ft_print_error(void)
{
    char    *error_message = "Error\n";
    int     i = 0;

    while (error_message[i] != '\0')
    {
        ft_putchar(error_message[i]);
        i++;
    }
}

void    ft_initialize(char *str, int *attr, int arr[4][4])
{
    if (attr[1] == 4)
    {
        attr[1] = 0;
        attr[2] += 1;
    }
    arr[attr[2]][attr[1]] = str[attr[0]] - '0';
    attr[1]++;
    attr[0]++;
}

int     ft_input_to_arr(char *str, int *attr, int arr[4][4])
{
    while (str[attr[0]] != '\0')
    {
        if (str[attr[0]] >= '1' && str[attr[0]] <= '4')
            ft_initialize(str, attr, arr);
        else if (str[attr[0]] == ' ')
            ++attr[0];
        else
        {
            ft_print_error();
            return (1);
        }
    }
    if (attr[0] != 31) // Adjusted for expected input length
    {
        ft_print_error();
        return (1);
    }
    return (0);
}
