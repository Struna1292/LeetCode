class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int output = 0;
        
        for (int i = 0; i < grid.size()-2; i++) {
            for (int j = 0; j < grid[i].size()-2; j++) {

                int currSum = 0;
                for (int currJ = j; currJ < j+3; currJ++) {
                    currSum += grid[i][currJ];
                    currSum += grid[i+2][currJ];
                }
                currSum += grid[i+1][j+1];

                output = max(currSum, output);
            }
        }

        return output;
    }
};