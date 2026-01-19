class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        vector<vector<int>> prefixGrid(mat.size(), vector<int>(mat[0].size()+1, 0));
        int output = 0;
        for (int i = 0; i < mat.size(); i++) {
            int currSum = 0;
            for (int j = 0; j < mat[i].size(); j++) {
                currSum += mat[i][j];
                prefixGrid[i][j+1] = currSum;

                if (output == 0 && mat[i][j] <= threshold) {
                    output = 1;
                }
            }
        }

        for (int squareSize = min(mat.size(), mat[0].size()); squareSize > 1; squareSize--) {
            for (int i = 0; i < mat.size() - squareSize + 1; i++) {
                for (int j = 0; j < mat[i].size() - squareSize + 1; j++) {
                    
                    int currSum = 0;
                    for (int currRow = 0; currRow < squareSize; currRow++) {
                        currSum += prefixGrid[i+currRow][j+squareSize] - prefixGrid[i+currRow][j];

                        if (currSum > threshold) {
                            break;
                        }
                    }

                    if (currSum <= threshold) {
                        return squareSize;
                    }
                }
            }
        }

        return output;
    }
};