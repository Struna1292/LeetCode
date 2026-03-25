class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        vector<long long> rows(grid.size()+1, 0);
        vector<long long> prefixRows = rows;

        long long rowsSum = 0;
        for (int i = 0; i < grid.size(); i++) {
            long long currSum = 0;
            for (int j = 0; j < grid[i].size(); j++) {
                currSum += grid[i][j];
            }

            rows[i+1] = currSum;

            rowsSum += currSum;
            prefixRows[i+1] = rowsSum;
        }

        rowsSum = 0;
        for (int i = grid.size()-1; i > 0; i--) {
            rowsSum += rows[i+1];

            if (rowsSum == prefixRows[i]) {
                return true;
            }
        }

        vector<long long> cols(grid[0].size()+1, 0);
        vector<long long> prefixCols = cols;

        long long colsSum = 0;
        for (int j = 0; j < grid[0].size(); j++) {
            long long currSum = 0;
            for (int i = 0; i < grid.size(); i++) {
                currSum += grid[i][j];
            }

            cols[j+1] = currSum;

            colsSum += currSum;
            prefixCols[j+1] = colsSum;            
        }

        colsSum = 0;
        for (int i = grid[0].size()-1; i > 0; i--) {
            colsSum += cols[i+1];

            if (colsSum == prefixCols[i]) {
                return true;
            }
        }

        return false;
    }
};