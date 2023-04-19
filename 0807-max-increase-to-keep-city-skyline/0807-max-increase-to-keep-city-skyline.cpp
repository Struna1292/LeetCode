class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<vector<int>> vertical;
        vector<vector<int>> horizontal;

        vector<int> curr;
        vector<int> empty;

        int biggest = 0;

        // build horizontal view
        for (int i = 0; i < grid.size(); i++)
        {
            biggest = 0;
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] > biggest)
                {
                    biggest = grid[i][j];
                }
            }
            for (int j = 0; j < grid[i].size(); j++)
            {
                curr.push_back(biggest);
            }
            horizontal.push_back(curr);
            curr = empty;
        }

        // build vertical view
        vertical = horizontal;
        int i = 0;
        int j = 0;
        biggest = 0;
        while (j < grid[i].size())
        {
            if (grid[i][j] > biggest)
            {
                biggest = grid[i][j];
            }
            if (i+1 == grid.size())
            {
                for (int k = 0; k < grid.size(); k++)
                {
                    vertical[k][j] = biggest;
                }
                i = 0;
                j++;
                biggest = 0;
            }
            else
            {
                i++;
            }
        }

        // confront both views and create gridNew 
        vector<vector<int>> gridNew = grid;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (vertical[i][j] < horizontal[i][j])
                {
                    gridNew[i][j] = vertical[i][j];
                }
                else
                {
                    gridNew[i][j] = horizontal[i][j];
                }
            }
        }

        // check gridNew and grid to get differences
        int output = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                output += gridNew[i][j] - grid[i][j];
            }
        }
        return output;
    }
};