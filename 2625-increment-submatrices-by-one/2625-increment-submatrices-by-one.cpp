class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        
        // while iterating over queries
        // incremenet first element of current row and (last + 1) decrement
        // then after queries iterate over grid and store curr sum
        // on every grid[i][j] first add it to curr sum then
        // write curr sum to grid[i][j]

        vector<vector<int>> grid(n, vector<int>(n, 0));

        for (int i = 0; i < queries.size(); i++) {
            int startJ = queries[i][1];
            int endJ = queries[i][3]+1;

            for (int currRow = queries[i][0]; currRow <= queries[i][2]; currRow++) {
                grid[currRow][startJ]++;

                if (endJ < grid.size()) {
                    grid[currRow][endJ]--;
                }
            }
        }

        for (int i = 0; i < grid.size(); i++) {
            int currSum = 0;
            for (int j = 0; j < grid[i].size(); j++) {
                currSum += grid[i][j];
                grid[i][j] = currSum;
            }
        }

        return grid;
    }
};