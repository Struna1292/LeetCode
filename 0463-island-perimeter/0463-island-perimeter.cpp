class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        
        int output = 0;

        for (int i = 0; i < grid.size(); i++)
        {
            int prev = 0;
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == 1 && prev != 1)
                {
                    output += 2;
                }
                prev = grid[i][j];
            }
        }

        for (int i = 0; i < grid[0].size(); i++)
        {
            int prev = 0;
            for (int j = 0; j < grid.size(); j++)
            {
                if (grid[j][i] == 1 && prev != 1)
                {
                    output += 2;
                }
                prev = grid[j][i];
            }
        }

        return output;
    }
};