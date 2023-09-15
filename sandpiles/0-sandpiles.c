#include "sandpiles.h"

/**
 * print_grid - prints a 3x3 grid
 * @grid: the grid
 */

static void print_grid(int grid[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (j)
                printf(" ");
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
}

/**
 * cpy - copies grid1 to grid2
 * @grid1: grid1
 * @grid2: grid2
 */

static void cpy(int grid1[3][3], int grid2[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            grid2[i][j] = grid1[i][j];
}

/**
 * topple - topples the values in the grid
 * @grid1: Grid to topple
 * @grid2: Using to copy for topple check
 */

static void topple(int grid1[3][3], int grid2[3][3])
{
    int i, j;

    cpy(grid1, grid2);
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (grid2[i][j] > 3)
            {
                grid1[i][j] -= 4;
                if (j - 1 > -1)
                    grid1[i][j - 1] += 1;
                if (j + 1 < 3)
                    grid1[i][j + 1] += 1;
                if (i - 1 > -1)
                    grid1[i - 1][j] += 1;
                if (i + 1 < 3)
                    grid1[i + 1][j] += 1;
            }
        }
    }
}

/**
 * is_stable - Determines if grid is stable
 * @grid1: checks if >3
 * Return: 0 if stable, 1 if unstable
 */

int is_stable(int grid1[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            if (grid1[i][j] > 3)
                return (1);
    return (0);
}

/**
 * sandpiles_sum - Computes sum of two sandpiles
 * @grid1: First grid 3x3 grid (0-3)
 * @grid2: Second 3x3 grid (0-3)
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
    int i, j, s;

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            grid1[i][j] += grid2[i][j];
    s = is_stable(grid1);
    while (s)
    {
        printf("=\n");
        print_grid(grid1);
        topple(grid1, grid2);
        s = is_stable(grid1);
    }
}
