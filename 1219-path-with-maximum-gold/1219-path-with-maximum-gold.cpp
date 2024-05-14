class Solution {
public:
    void helper(int i, int j, int curr, vector<vector<int>>& grid, int& output)
    {

        if (i-1 >= 0 && grid[i-1][j] != 0)
        {
            int temp = grid[i-1][j];
            grid[i-1][j] = 0;
            helper(i-1, j, (curr+temp), grid, output);
            grid[i-1][j] = temp;
        }
        if (j+1 < grid[0].size() && grid[i][j+1] != 0)
        {
            int temp = grid[i][j+1];
            grid[i][j+1] = 0;
            helper(i, j+1, (curr+temp), grid, output);
            grid[i][j+1] = temp;
        }
        if (i+1 < grid.size() && grid[i+1][j] != 0)
        {
            int temp = grid[i+1][j];
            grid[i+1][j] = 0;
            helper(i+1, j, (curr+temp), grid, output);
            grid[i+1][j] = temp;
        }
        if (j-1 >= 0 && grid[i][j-1] != 0)
        {
            int temp = grid[i][j-1];
            grid[i][j-1] = 0;
            helper(i, j-1, (curr+temp), grid, output);
            grid[i][j-1] = temp;
        }

        if (curr > output)
        {
            output = curr;
        }
    }

    int getMaximumGold(vector<vector<int>>& grid) {

        int output = 0;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] != 0)
                {
                    int temp = grid[i][j];
                    grid[i][j] = 0;
                    helper(i, j, temp, grid, output);
                    grid[i][j] = temp;
                }
            }
        }

        return output;
    }
};