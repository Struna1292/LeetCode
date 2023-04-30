class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if (mat.size() * mat[0].size() != r * c)
        {
            return mat;
        }

        vector<vector<int>> output(r, vector<int>(c, 0)) ;

        int k = 0;
        int l = 0;
        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[i].size(); j++)
            {
                output[k][l] = mat[i][j];
                if (l+1 == c)
                {
                    l = 0;
                    k++;
                }
                else
                {
                    l++;
                }
            }
        }
        return output;
    }
};