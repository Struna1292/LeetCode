class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {

        vector<vector<int>> answer(mat.size(), vector<int>(mat[0].size(), 0));

        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[i].size(); j++)
            {
                int rMin = i-k < 0 ? 0 : i-k;
                int rMax = i+k > mat.size()-1 ? mat.size()-1 : i+k;
                int cMin = j-k < 0 ? 0 : j-k;
                int cMax = j+k > mat[0].size()-1 ? mat[0].size()-1 : j+k;

                for (int r = rMin; r <= rMax; r++)
                {
                    for (int c = cMin; c <= cMax; c++)
                    {
                        answer[i][j] += mat[r][c];
                    }
                }

            }
        }

        return answer;
    }
};