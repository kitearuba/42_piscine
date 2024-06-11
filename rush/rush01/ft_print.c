#include <unistd.h>

#define MAX_SIZE 4

void ft_putchar(char c);

void ft_print_criteria(int arr[MAX_SIZE][MAX_SIZE])
{
    int i, j;
    char ans;

    for (i = 0; i < MAX_SIZE; i++)
    {
        for (j = 0; j < MAX_SIZE - 1; j++)
        {
            ans = arr[i][j] + '0'; // Convert int to char
            ft_putchar(ans);
            ft_putchar(' ');
        }
        ans = arr[i][j] + '0'; // Last number in the row, avoiding trailing space
        ft_putchar(ans);
        ft_putchar('\n');
    }
}
