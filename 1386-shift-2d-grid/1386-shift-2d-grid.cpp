class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        k %= (grid.size()*grid[0].size());

        if (k == 0)
        {
            return grid;
        }

        vector<vector<int>> shifted(grid.size(), vector<int>(grid[0].size(), 0));

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                int indexI = i;
                int indexJ = j+k;
                while (indexJ >= grid[i].size())
                {
                    indexJ -= grid[i].size();

                    indexI++;
                    if (indexI >= grid.size())
                    {
                        indexI = 0;
                    }
                }

                shifted[indexI][indexJ] = grid[i][j];
            }
        }

        return shifted;
    }
};