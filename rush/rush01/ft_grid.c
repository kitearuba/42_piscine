#include <unistd.h>

#define MAX_SIZE 4
#define INCREMENT 0
#define DECREMENT 1

void ft_print_criteria(int grid[MAX_SIZE][MAX_SIZE]);

void ft_increment_assign(int grid[MAX_SIZE][MAX_SIZE], int fixed, int is_row, int direction)
{
    int index;

    if (direction == INCREMENT)
    {
        for (index = 0; index < MAX_SIZE; index++)
        {
            if (is_row)
                grid[fixed][index] = index + 1;
            else
                grid[index][fixed] = index + 1;
        }
    }
    else // DECREMENT
    {
        for (index = MAX_SIZE - 1; index >= 0; index--)
        {
            if (is_row)
                grid[fixed][index] = MAX_SIZE - index;
            else
                grid[index][fixed] = MAX_SIZE - index;
        }
    }
}

void ft_assign_for_one(int grid[MAX_SIZE][MAX_SIZE], int position, int index)
{
    if (position == 0)
        grid[0][index] = MAX_SIZE;
    else if (position == 1)
        grid[MAX_SIZE - 1][index] = MAX_SIZE;
    else if (position == 2)
        grid[index][0] = MAX_SIZE;
    else // position == 3
        grid[index][MAX_SIZE - 1] = MAX_SIZE;
}

void ft_assign_values(int grid[MAX_SIZE][MAX_SIZE], int position, int index, int value)
{
    if (value == 1)
        ft_assign_for_one(grid, position, index);
    else if (position < 2) // Top or Bottom
        ft_increment_assign(grid, index, 1, position == 0 ? INCREMENT : DECREMENT);
    else // Left or Right
        ft_increment_assign(grid, index, 0, position == 2 ? INCREMENT : DECREMENT);
}

void ft_init_grid(int criteria[MAX_SIZE][MAX_SIZE], int grid[MAX_SIZE][MAX_SIZE])
{
    int i, j;

    for (i = 0; i < MAX_SIZE; i++)
    {
        for (j = 0; j < MAX_SIZE; j++)
        {
            if (criteria[i][j] == MAX_SIZE || criteria[i][j] == 1)
                ft_assign_values(grid, i, j, criteria[i][j]);
        }
    }
}
