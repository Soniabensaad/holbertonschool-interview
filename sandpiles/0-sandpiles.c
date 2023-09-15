#include <stdio.h>

void print_grid(int grid[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d", grid[i][j]);
            if (j < 2) {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void topple(int grid[3][3], int x, int y) {
    grid[x][y] -= 4;
    if (x > 0) grid[x - 1][y]++;
    if (x < 2) grid[x + 1][y]++;
    if (y > 0) grid[x][y - 1]++;
    if (y < 2) grid[x][y + 1]++;
}

void sandpiles_sum(int grid1[3][3], int grid2[3][3]) {
    int result[3][3];

   
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result[i][j] = grid1[i][j] + grid2[i][j];
        }
    }

    while (1) {
        int unstable = 0;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (result[i][j] > 3) {
                    unstable = 1;
                    break;
                }
            }
            if (unstable) break;
        }

        // If no unstable cells, exit the loop
        if (!unstable) break;

        // Topple unstable cells
        int temp[3][3];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                temp[i][j] = result[i][j];
            }
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (temp[i][j] > 3) {
                    topple(result, i, j);
                }
            }
        }

        if (unstable) {
            print_grid(result);
            printf("=\n");
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            grid1[i][j] = result[i][j];
        }
    }
}
