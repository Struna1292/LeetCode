class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (j+1 < grid[i].size() && i+1 < grid.size())
                {
                    int black = 0;
                    int white = 0;

                    if (grid[i][j] == 'W')
                    {
                        white++;
                    }
                    else
                    {
                        black++;
                    }

                    if (grid[i][j+1] == 'W')
                    {
                        white++;
                    }
                    else
                    {
                        black++;
                    }

                    if (grid[i+1][j] == 'W')
                    {
                        white++;
                    }
                    else
                    {
                        black++;
                    }

                    if (grid[i+1][j+1] == 'W')
                    {
                        white++;
                    }
                    else
                    {
                        black++;
                    }

                    if (white >= 3 || black >= 3)
                    {
                        return true;
                    }
                }

            }
        }

        return false;
    }
};