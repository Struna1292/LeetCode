class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int output = 0;

        for (int i = 0; i < grid.size(); i++) {
            output += end(grid[i]) - upper_bound(begin(grid[i]), end(grid[i]), 0, greater<int>());
        }

        return output;
    }
};