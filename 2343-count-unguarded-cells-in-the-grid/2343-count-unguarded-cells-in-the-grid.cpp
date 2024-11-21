class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        sort(begin(guards),end(guards));
        sort(begin(walls), end(walls));

        vector<vector<int>> grid(m, vector<int>(n, 0));

        // 0 - empty space
        // 1 - guarded space
        // 2 - guard
        // 3 - wall

        int currGuards = 0;
        int currWalls = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (currGuards < guards.size() && guards[currGuards][0] == i && guards[currGuards][1] == j)
                {
                    grid[i][j] = 2; 
                    currGuards++;
                }

                if (currWalls < walls.size() && walls[currWalls][0] == i && walls[currWalls][1] == j)
                {
                    grid[i][j] = 3;
                    currWalls++;
                }
            }
        }


        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 2)
                {
                    //check up
                    int k = i-1;
                    while (k >= 0 && grid[k][j] != 3 && grid[k][j] != 2)
                    {
                        grid[k][j] = 1;
                        k--;
                    }

                    //check right
                    k = j+1;
                    while (k < n && grid[i][k] != 3 && grid[i][k] != 2)
                    {
                        grid[i][k] = 1;
                        k++;
                    }


                    //check down
                    k = i+1;
                    while (k < m && grid[k][j] != 3 && grid[k][j] != 2)
                    {
                        grid[k][j] = 1;
                        k++;
                    }


                    //check left
                    k = j-1;
                    while (k >= 0 && grid[i][k] != 3 && grid[i][k] != 2)
                    {
                        grid[i][k] = 1;
                        k--;
                    }
                }
            }
        }

        int output = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                {
                    output++;
                }
            }
        }

        return output;
    }
};