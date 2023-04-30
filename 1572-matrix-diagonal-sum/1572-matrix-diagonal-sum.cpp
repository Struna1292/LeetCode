class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int output = 0;
        int j = mat.size()-1;
        for (int i = 0; i < mat.size(); i++)
        {
            output += mat[i][i];
            if (i != j)
            {
                output += mat[i][j];
            }
            j--;
        }
        return output;
    }
};