class neighborSum {
public:
    vector<vector<int>> g;

    neighborSum(vector<vector<int>>& grid) {
        g = grid;
    }
    
    int adjacentSum(int value) {

        for (int i = 0; i < g.size(); i++)
        {
            for (int j = 0; j < g[i].size(); j++)
            {
                if (g[i][j] == value)
                {
                    int output = 0;

                    if (i > 0)
                    {
                        output += g[i-1][j];
                    }

                    if (i+1 < g.size())
                    {
                        output += g[i+1][j];
                    }

                    if (j > 0)
                    {
                        output += g[i][j-1];
                    }

                    if (j+1 < g.size())
                    {
                        output += g[i][j+1];
                    }

                    return output;
                }
            }
        }

        return 0;
    }
    
    int diagonalSum(int value) {

        for (int i = 0; i < g.size(); i++)
        {
            for (int j = 0; j < g[i].size(); j++)
            {
                if (g[i][j] == value)
                {
                    int output = 0;

                    if (i > 0 && j > 0)
                    {
                        output += g[i-1][j-1];
                    }

                    if (i > 0 && j+1 < g.size())
                    {
                        output += g[i-1][j+1];
                    }

                    if (i+1 < g.size() && j > 0)
                    {
                        output += g[i+1][j-1];
                    }

                    if (i+1 < g.size() && j+1 < g.size())
                    {
                        output += g[i+1][j+1];
                    }

                    return output;
                }
            }
        }

        return 0;
    }
};

/**
 * Your neighborSum object will be instantiated and called as such:
 * neighborSum* obj = new neighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */