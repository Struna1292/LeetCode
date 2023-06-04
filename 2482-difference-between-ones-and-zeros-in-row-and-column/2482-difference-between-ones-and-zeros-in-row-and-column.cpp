class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        vector<vector<int>> ones(r, vector<int>(c ,0));

        for (int i = 0; i < r; i++)
        {
            int counter = 0;
            for (int j = 0 ; j < c; j++)
            {
                if (grid[i][j] == 1)
                {
                    counter++;
                }
            }
            for (int j = 0 ; j < c; j++)
            {
                ones[i][j] = counter;
            }
        }

        for (int i = 0; i < c; i++)
        {
            int counter = 0;
            for (int j = 0; j < r; j++)
            {
                if (grid[j][i] == 1)
                {
                    counter++;
                }
            }

            for (int j = 0; j < r; j++)
            {
                ones[j][i] += counter;
            }
        }


        vector<vector<int>> zeros(r, vector<int>(c ,0));

        for (int i = 0; i < r; i++)
        {
            int counter = 0;
            for (int j = 0 ; j < c; j++)
            {
                if (grid[i][j] == 0)
                {
                    counter++;
                }
            }
            for (int j = 0 ; j < c; j++)
            {
                zeros[i][j] = counter;
            }
        }

        for (int i = 0; i < c; i++)
        {
            int counter = 0;
            for (int j = 0; j < r; j++)
            {
                if (grid[j][i] == 0)
                {
                    counter++;
                }
            }

            for (int j = 0; j < r; j++)
            {
                zeros[j][i] += counter;
            }
        }

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                grid[i][j] = ones[i][j] - zeros[i][j];
            }
        }

        return grid;
    }
};