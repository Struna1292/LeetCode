class Solution {
public:

    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<vector<int>> matrix(m, vector<int>(n, 0));

        for (int i = 0; i < indices.size(); i++)
        {
            for (int j = 0; j < n; j++)
            {
                matrix[indices[i][0]][j]++;
            }

            for (int j = 0; j < m; j++)
            {
                matrix[j][indices[i][1]]++;
            }
        }


        int odds = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] % 2 != 0)
                {
                    odds++;
                }
            }
        }

        return odds;
    }
};