class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 1)
        {
            return {{1}};
        }
        vector<vector<int>> output = {{1}, {1,1}};

        for (int i = 2; i < numRows; i++)
        {
            vector<int> curr(i+1, 1);

            for (int j = 0; j < output[i-1].size()-1; j++)
            {
                curr[j+1] = output[i-1][j] + output[i-1][j+1];
            }

            output.push_back(curr);
        }

        return output;
    }

    vector<int> getRow(int rowIndex) {
        
        vector<vector<int>> triangle = generate(rowIndex+1);

        return triangle[rowIndex];
    }
};