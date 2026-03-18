class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        if (grid[0][0] > k) {
            return 0;
        }

        for (int i = 0; i < grid.size(); i++) {
            int currSum = 0;
            for (int j = 0; j < grid[i].size(); j++) {
                currSum += grid[i][j];
                grid[i][j] = currSum;
            }
        }

        for (int i = 0; i < grid[0].size(); i++) {
            int currSum = 0;
            for (int j = 0; j < grid.size(); j++) {
                currSum += grid[j][i];
                grid[j][i] = currSum;
            }
        }

        int output = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] <= k) {
                    output++;
                }
            }
        }

        return output;
    }
};