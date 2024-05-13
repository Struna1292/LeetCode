class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        
        for (int i = 0; i < grid.size(); i++)
        {
            if (grid[i][0] == 0)
            {
                for (int j = 0; j < grid[i].size(); j++)
                {
                    if (grid[i][j] == 0)
                    {
                        grid[i][j] = 1;
                    }
                    else
                    {
                        grid[i][j] = 0;
                    }
                }
            }
        }

        
        for (int i = 0; i < grid[0].size(); i++)
        {
            int ones = 0;
            int zeros = 0;
            for (int j = 0; j < grid.size(); j++)
            {
                if (grid[j][i] == 0)
                {
                    zeros++;
                }
                else
                {
                    ones++;
                }
            }

            if (zeros > ones)
            {
                for (int j = 0; j < grid.size(); j++)
                {
                    if (grid[j][i] == 0)
                    {
                        grid[j][i] = 1;
                    }
                    else
                    {
                        grid[j][i] = 0;
                    }
                }
            }
        }

        int output = 0;

        for (int i = 0; i < grid.size(); i++)
        {
            int curr = 0;

            for (int j = 0; j < grid[i].size(); j++)
            {

                curr |= grid[i][j];

                if (j+1 < grid[i].size())
                {
                    curr <<= 1;
                }
            }
            output += curr;
        }


        return output;
    }
};