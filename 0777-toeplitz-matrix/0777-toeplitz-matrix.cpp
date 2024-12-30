class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        
        for (int i = 0; i < matrix[0].size(); i++)
        {
            for (int j = 0; j < matrix.size(); j++)
            {
                if (i+j < matrix[0].size())
                {
                    if (j-1 >= 0 && i+j-1 >= 0)
                    {
                        if (matrix[j][i+j] != matrix[j-1][i+j-1])
                        {
                            return false;
                        }
                    }
                }
            }
        }

        for (int i = 1; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (i+j < matrix.size())
                {
                    if (j-1 >= 0 && i+j-1 >= 0)
                    {
                        if (matrix[i+j][j] != matrix[i+j-1][j-1])
                        {
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};