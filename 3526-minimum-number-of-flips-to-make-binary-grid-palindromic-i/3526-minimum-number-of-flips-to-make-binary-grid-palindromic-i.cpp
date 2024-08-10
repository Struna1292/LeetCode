class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        
        int rowSwaps = 0;

        for (int i = 0; i < grid.size(); i++)
        {
            int j = 0;
            int k = grid[i].size()-1;

            while (j < k)
            {
                if (grid[i][j] != grid[i][k])
                {
                    rowSwaps++;
                }
                j++;
                k--;
            }
        }

        int colSwaps = 0;

        for (int i = 0; i < grid[0].size(); i++)
        {
            int j = 0;
            int k = grid.size()-1;

            while (j < k)
            {
                if (grid[j][i] != grid[k][i])
                {
                    colSwaps++;
                }
                j++;
                k--;
            }
        }

        if (colSwaps < rowSwaps)
        {
            return colSwaps;
        }

        return rowSwaps;
    }
};