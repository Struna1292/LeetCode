class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        
        vector<int> output;

        int counter = 2;

        for (int i = 0; i < mat.size(); i++)
        {
            int row = i;
            int column = 0;

            vector<int> curr;

            while (row >= 0 && column < mat[0].size())
            {
                curr.push_back(mat[row][column]);
                row--;
                column++;
            }

            if (counter % 2 == 0)
            {
                for (int j = 0; j < curr.size(); j++)
                {
                    output.push_back(curr[j]);
                }
            }
            else
            {
                for (int j = curr.size()-1; j >= 0; j--)
                {
                    output.push_back(curr[j]);
                }
            }
            
            counter++;
        }

        for (int i = 1; i < mat[0].size(); i++)
        {
            int row = mat.size()-1;
            int column = i;

            vector<int> curr;

            while (row >= 0 && column < mat[0].size())
            {
                curr.push_back(mat[row][column]);
                row--;
                column++;
            }

            if (counter % 2 == 0)
            {
                for (int j = 0; j < curr.size(); j++)
                {
                    output.push_back(curr[j]);
                }
            }
            else
            {
                for (int j = curr.size()-1; j >= 0; j--)
                {
                    output.push_back(curr[j]);
                }
            }
            
            counter++;
        }

        return output;
    }
};