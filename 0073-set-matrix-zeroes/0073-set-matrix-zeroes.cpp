class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>> zeros;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                if (matrix[i][j] == 0)
                {
                    zeros.push_back({i,j});
                }
            }
        }
        
        for (int i = 0; i < zeros.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                matrix[zeros[i].first][j] = 0;
            }
            for (int j = 0; j < matrix.size(); j++)
            {
                matrix[j][zeros[i].second] = 0;
            }
        }

    }
};