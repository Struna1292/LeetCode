class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        
        int output = 0;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == 1 || grid[i][j] == 2)
                {
                    for (int k = j+1; k < grid[i].size(); k++)
                    {
                        if (grid[i][k] == 1)
                        {
                            if (grid[i][j] == 2)
                            {
                                output++;
                            }
                            else
                            {
                                grid[i][j] = 2;
                                output += 2;
                            }
                            grid[i][k] = 2;
                            break;
                        }
                        if (grid[i][k] == 2)
                        {
                            if (grid[i][j] == 1)
                            {
                                grid[i][j] = 2;
                                output++;
                            }
                            break;
                        }
                    }

                    for (int k = i+1; k < grid.size(); k++)
                    {
                        if (grid[k][j] == 1)
                        {
                            if (grid[i][j] == 2)
                            {
                                output++;
                            }
                            else
                            {
                                grid[i][j] = 2;
                                output += 2;
                            }
                            grid[k][j] = 2;
                            break;
                        }
                        if (grid[k][j] == 2)
                        {
                            if (grid[i][j] == 1)
                            {
                                grid[i][j] = 2;
                                output++;
                            }
                            break;
                        }
                    }

                }
            }
        }

        return output;
    }
};