class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = i; j < matrix[i].size(); j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (int i = 0; i < matrix.size(); i++) {
            int j = 0;
            int k = matrix[i].size()-1;

            while (j < k) {
                swap(matrix[i][j], matrix[i][k]);
                j++;
                k--;
            }
        }
    }
};