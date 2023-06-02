class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {

        if (mat[0].size() == 1)
        {
            return mat;
        }
        
        for (int i = 1; i < mat[0].size(); i++)
        {
            vector<int> curr;
            for (int j = 0, k = i; j < mat.size() && k < mat[0].size(); j++, k++)
            {
                curr.push_back(mat[j][k]);
            }

            sort(begin(curr), end(curr));

            for (int j = 0, k = i; j < mat.size() && k < mat[0].size(); j++, k++)
            {
                mat[j][k] = curr[j];
            }
        }

        for (int i = 0; i < mat.size(); i++)
        {
            vector<int> curr;
            for (int j = 0, k = i; j < mat[0].size() && k < mat.size(); j++, k++)
            {
                curr.push_back(mat[k][j]);
            }

            sort(begin(curr), end(curr));

            for (int j = 0, k = i; j < mat[0].size() && k < mat.size(); j++, k++)
            {
                mat[k][j] = curr[j];
            }
        }

        return mat;
    }
};