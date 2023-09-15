void topple(int grid[3][3])
{
    int temp[3][3] = {{0}}; // Initialize temp to zeros

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[i][j] >= 4)
            {
                int grainsToDistribute = grid[i][j] / 4;
                grid[i][j] %= 4; // Keep the remainder after distributing

                if (i > 0)
                    temp[i - 1][j] += grainsToDistribute;
                if (i < 2)
                    temp[i + 1][j] += grainsToDistribute;
                if (j > 0)
                    temp[i][j - 1] += grainsToDistribute;
                if (j < 2)
                    temp[i][j + 1] += grainsToDistribute;
            }
        }
    }

    // Add the redistributed grains back to the grid
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            grid[i][j] += temp[i][j];
        }
    }
}
