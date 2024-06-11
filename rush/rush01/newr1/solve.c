#include <unistd.h>
#include "ft_putchar.h"

void ft_solve(int arr[4][4]);
void print_criteria(int arr[4][4]);
void init_grid(int arr[4][4], int grid[4][4]);
int ft_recursion(int grid[4][4], int arr[4][4], int r, int c);
int ft_is_valid(int grid[4][4], int arr[4][4], int *attr);
int ft_condition(int arr[4][4], int r, int c);
int ft_condition_loop(int *i, int *attr, int arr[4][4], int grid[4][4]);
void ft_print_error(void);

/*void ft_solve(int arr[4][4]) {
    int grid[4][4];
    int i, j;
    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
            grid[i][j] = -1;
    init_grid(arr, grid);
    if (!ft_recursion(grid, arr, 0, 0))
        print_criteria(grid);
    else
        ft_print_error();
}
*/
void ft_solve(int arr[4][4]) {
    int grid[4][4] = {{-1, -1, -1, -1}, {-1, -1, -1, -1}, {-1, -1, -1, -1}, {-1, -1, -1, -1}};
    ft_init_grid(arr, grid);
    if (!ft_recursion(grid, arr, 0, 0))
        ft_print_criteria(grid);
    else
        ft_print_error();
}

int	ft_is_valid(int grid[4][4], int arr[4][4], int *attr)
{
	grid[attr[0]][attr[1]] = attr[2];
	if (row_leftright(0, attr, grid, arr) == 1)
		return (1);
	if (col_updown(0, attr, grid, arr) == 1)
		return (1);
	if (rightleft(0, attr, grid, arr) == 1)
		return (1);:w
	if (downup(0, attr, grid, arr) == 1)
		return (1);
	return (0);
}

int	ft_condition(int arr[4][4], int r, int c)
{
	if ((r == 0) && (arr[0][c] == 2 || arr[0][c] == 3))
		return (1);
	if ((r == 3) && (arr[1][c] == 2 || arr[1][c] == 3))
		return (1);
	if ((c == 0) && (arr[2][r] == 2 || arr[2][r] == 3))
		return (1);
	if ((c == 3) && (arr[3][r] == 2 || arr[3][r] == 3))
		return (1);
	return (0);
}

int	ft_condition_loop(int *i, int *attr, int arr[4][4], int grid[4][4])
{
	int	r;
	int	c;

	r = attr[0];
	c = attr[1];
	while (++*i < 5)
	{
		if (*i == 4 && (attr[0] == 0 || attr[1] == 0 \
			|| attr[0] == 3 || attr[1] == 3))
		{
			if (condition(arr, r, c) == 1)
				continue ;
		}
		attr[2] = *i;
		if (is_valid(grid, arr, attr) == 0)
		{
			if (recursion(grid, arr, r, c + 1) == 0)
				return (0);
			grid[r][c] = -1;
		}
		else
			grid[r][c] = -1;
	}
	return (1);
}

int	ft_recursion(int grid[4][4], int arr[4][4], int r, int c)
{
	int	i;
	int	attr[3];

	i = 0;
	attr[0] = r;
	attr[1] = c;
	if (r == 4)
		return (0);
	else if (c == 4)
		return (recursion(grid, arr, r + 1, 0));
	else if (grid[r][c] != -1)
		return (recursion(grid, arr, r, c + 1));
	else
	{
		if (condition_loop(&i, attr, arr, grid) == 0)
			return (0);
		else
			return (1);
	}
}
