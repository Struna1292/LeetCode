class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        
        vector<int> columns(matrix[0].size(), -1);
        vector<int> rows(matrix.size(), -1);

        for (int i = 0; i < matrix.size(); i++)
        {
            int curr = matrix[i][0];
            for (int j = 1; j < matrix[i].size(); j++)
            {
                if (matrix[i][j] < curr)
                {
                    curr = matrix[i][j];
                }
            }

            rows[i] = curr;
        }


        for (int i = 0; i < matrix[0].size(); i++)
        {
            int curr = matrix[0][i];
            for (int j = 1; j < matrix.size(); j++)
            {
                if (matrix[j][i] > curr)
                {
                    curr = matrix[j][i];
                }
            }

            columns[i] = curr;
        }


        vector<int> output;

        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                if (matrix[i][j] == columns[j] && matrix[i][j] == rows[i])
                {
                    output.push_back(matrix[i][j]);
                }
            }
        }
        
        return output;
    }
};