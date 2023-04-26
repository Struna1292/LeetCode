class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> output = matrix;
        int k = 0;
        int l = 0;
        for (int i = output.size()-1; i >= 0; i--)
        {
            l = 0;
            for (int j = 0; j < output.size(); j++)
            {
                output[j][i] = matrix[k][l];
                l++;
            }
            k++;
        }
        matrix = output;
    }
};