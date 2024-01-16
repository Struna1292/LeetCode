class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        vector<vector<int>> output(grid.size()-2, vector<int>(grid.size()-2, 1));

        for (int i = 0; i < grid.size()-2; i++)
        {
            for (int j = 0; j < grid.size()-2; j++)
            {

                int curr = 1;

                for (int k = i; k < i+3; k++)
                {
                    for (int l = j; l < j+3; l++)
                    {
                        if (grid[k][l] > curr)
                        {
                            curr = grid[k][l];
                        }
                    }
                }
                output[i][j] = curr;
            }
        }

        return output;
    }
};