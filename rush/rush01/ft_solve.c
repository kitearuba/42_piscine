#include <unistd.h>

void ft_putchar(char c);
void ft_solve(int arr[4][4]);
void ft_print_criteria(int arr[4][4]);
void ft_init_grid(int arr[4][4], int grid[4][4]);
int ft_recursion(int grid[4][4], int arr[4][4], int r, int c);
int ft_check_visibility(int from_direction, int *position, int grid[4][4], int arr[4][4]);

void ft_putchar(char c) {
    write(1, &c, 1);
}

int ft_is_valid_placement(int grid[4][4], int arr[4][4], int *pos) {
    int visibility_checks[4] = {0, 1, 2, 3};
    for (int i = 0; i < 4; i++) {
        if (ft_check_visibility(visibility_checks[i], pos, grid, arr) == 1) {
            return 1;
        }
    }
    return 0;
}

int ft_should_continue(int arr[4][4], int r, int c) {
    return (r == 0 || c == 0 || r == 3 || c == 3) && (arr[r % 4][c % 4] == 2 || arr[r % 4][c % 4] == 3);
}

int ft_recursion(int grid[4][4], int arr[4][4], int r, int c) {
    if (r == 4) return 0;
    if (c == 4) return ft_recursion(grid, arr, r + 1, 0);
    if (grid[r][c] != -1) return ft_recursion(grid, arr, r, c + 1);

    for (int i = 1; i <= 4; i++) {
        int pos[3] = {r, c, i};
        if (ft_is_valid_placement(grid, arr, pos)) {
            grid[r][c] = i;
            if (ft_recursion(grid, arr, r, c + 1) == 0) return 0;
            grid[r][c] = -1;
        }
    }
    return 1;
}

void ft_solve(int arr[4][4]) {
    int grid[4][4] = {{-1}};
    ft_init_grid(arr, grid);
    if (ft_recursion(grid, arr, 0, 0) == 0) ft_print_criteria(grid);
    else {
        char *error_msg = "Error";
        while (*error_msg) {
            ft_putchar(*error_msg++);
        }
    }
}
