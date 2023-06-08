class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {

        int output = 0;

        int n = grid.size();

        for (int i = 0; i < n; i++)
        {
            int j = 0;
            int k = 0;
            while (j < n && k < n)
            {
                if (grid[i][j] == grid[j][k])
                {
                    if (j+1 >= n)
                    {
                        output++;
                        j = 0;
                        k++;
                    }
                    else
                    {
                        j++;
                    }
                }
                else
                {
                    j = 0;
                    k++;
                }
            }

            if (j == n)
            {
                output++;
            }
        }

        return output;
    }
};