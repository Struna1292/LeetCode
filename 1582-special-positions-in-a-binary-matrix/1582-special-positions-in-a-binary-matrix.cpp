class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        vector<int> rows(mat.size(), 0);
        vector<int> columns(mat[0].size(), 0);

        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[i].size(); j++)
            {
                if (mat[i][j] == 1)
                {
                    rows[i]++;
                    columns[j]++;
                }
            }
        }

        int output = 0;

        
        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[i].size(); j++)
            {
                if (mat[i][j] == 1 && rows[i] == 1 && columns[j] == 1)
                {
                    output++;
                }
            }
        }

        return output;
    }
};