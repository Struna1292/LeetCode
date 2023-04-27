class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        for (int i = 0; i < matrix.size(); i++)
        {
            if (matrix[i][matrix[i].size()-1] >= target)
            {
                for (int j = 0; j < matrix[i].size(); j++)
                {
                    if (matrix[i][j] == target)
                    {
                        return true;
                    }
                }
                return false;
            }
        }

        return false;
    }
};