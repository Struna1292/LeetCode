class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {

        vector<int> minRows;
        for (int i = 0; i < matrix.size(); i++)
        {
            int min = matrix[i][0];
            for (int j = 1; j < matrix[i].size(); j++)
            {
                if (min > matrix[i][j])
                {
                    min = matrix[i][j];
                }
            }
            minRows.push_back(min);
        }

        vector<int> maxCols;
        for(int i = 0; i < matrix[0].size(); i++)
        {
            int max = matrix[0][i];
            for (int j = 1; j < matrix.size(); j++)
            {
                if (max < matrix[j][i])
                {
                    max = matrix[j][i];
                }
            }
            maxCols.push_back(max);
        }

        vector<int> output;
        for (int i = 0; i < minRows.size(); i++)
        {
            for (int j = 0; j < maxCols.size(); j++)
            {
                if (minRows[i] == maxCols[j])
                {
                    output.push_back(minRows[i]);
                }
            }
        }

        return output;
    }
};