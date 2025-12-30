class Solution {
public:
    bool isMagicSquare(int startI, int startJ, vector<vector<int>>& grid) {
        int sum = 0;
        int nums[9] = { 0 };

        for (int i = 0; i < 3; i++) {
            int currRow = 0;
            for (int j = 0; j < 3; j++) {
                if (grid[startI+i][startJ+j] == 0 || grid[startI+i][startJ+j] >= 10) {
                    return false;
                }
                
                nums[grid[startI+i][startJ+j]-1]++;
                if (nums[grid[startI+i][startJ+j]-1] != 1) {
                    return false;
                }

                currRow += grid[startI+i][startJ+j];
            }

            if (sum == 0) {
                sum = currRow;
            }
            else if (sum != currRow) {
                return false;
            }
        }

        for (int i = 0; i < 3; i++) {
            int currCol = 0;
            for (int j = 0; j < 3; j++) {
                currCol += grid[startI+j][startJ+i];
            }

            if (sum != currCol) {
                return false;
            }
        }
        
        int currDiagonal = 0;
        for (int i = 0; i < 3; i++) {
            currDiagonal += grid[startI+i][startJ+i];
        }
        if (sum != currDiagonal) {
            return false;
        }

        currDiagonal = 0;
        for (int i = 0; i < 3; i++) {
            currDiagonal += grid[startI+2-i][startJ+i];
        }
        if (sum != currDiagonal) {
            return false;
        }        

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {

        if (grid.size() < 3 || grid[0].size() < 3) {
            return 0;
        }
        
        int output = 0;
        for (int i = 0; i < grid.size()-2; i++) {
            for (int j = 0; j < grid[i].size()-2; j++) {
                if (isMagicSquare(i, j, grid)) {
                    output++;
                }
            }
        }

        return output;
    }
};