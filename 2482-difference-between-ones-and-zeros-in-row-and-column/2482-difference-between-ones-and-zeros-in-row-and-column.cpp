class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        vector<vector<int>> output(grid.size(), vector<int>(grid[0].size(), 0));

        vector<int> rowsOne(grid.size(), 0);
        vector<int> rowsZero(grid.size(), 0);

        vector<int> columnsOne(grid[0].size(), 0);
        vector<int> columnsZero(grid[0].size(), 0);

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == 0)
                {
                    rowsZero[i]++;
                    columnsZero[j]++;
                }
                else
                {
                    rowsOne[i]++;
                    columnsOne[j]++;
                }
            }
        }

        for (int i = 0; i < output.size(); i++)
        {
            for (int j = 0; j < output[i].size(); j++)
            {
                output[i][j] = rowsOne[i] + columnsOne[j] - rowsZero[i] - columnsZero[j];
            }
        }

        return output;
    }
};