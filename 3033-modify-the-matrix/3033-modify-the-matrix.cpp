class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        vector<int> columnMax(matrix[0].size(), 0);

        for (int i = 0; i < matrix[0].size(); i++)
        {
            int currBiggest = matrix[0][i];
            for (int j = 0; j < matrix.size(); j++)
            {
                if (matrix[j][i] > currBiggest)
                {
                    currBiggest = matrix[j][i];
                }
            }
            columnMax[i] = currBiggest;
        }

        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                if (matrix[i][j] == -1)
                {
                    matrix[i][j] = columnMax[j];
                }
            }
        }

        return matrix;
    }
};