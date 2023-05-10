class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>>matrix (n ,vector<int>(n, 0));

        int j = 0;

        int num = 1;
        int range = 0;
        int size = matrix.size() * matrix[0].size();
        while (num-1 < size)
        {
            j = range;
            for (int i = range; i < matrix[0].size()-range; i++)
            {
                matrix[j][i] = num;
                num++;
            }

            j = matrix[0].size()-1-range;
            for (int i = range+1; i < matrix.size()-range; i++)
            {
                matrix[i][j] = num;
                num++;
            }

            j = matrix.size()-1-range;
            for (int i = matrix[0].size()-2-range; i >= range; i--)
            {
                matrix[j][i] = num;
                num++;
            }

            j = range;
            for (int i = matrix.size()-2-range; i >= range+1; i--)
            {
                matrix[i][j] = num;
                num++;
            }
            range++;
        }

        return matrix;
    }
};