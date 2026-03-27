class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        k %= mat[0].size();

        if (k == 0) {
            return true;
        }

        for (int i = 0; i < mat.size(); i++) {
            vector<int> currRow = mat[i];

            for (int j = 0; j < mat[i].size(); j++) {
                int index = j;
                if (mat[i][j] % 2 == 0) {
                    index -= k;
                    if (index < 0) {
                        index += mat[i].size();
                    }
                }
                else {
                    index += k;
                    index %= mat[i].size();
                }

                currRow[index] = mat[i][j];
            }


            for (int j = 0; j < currRow.size(); j++) {
                if (currRow[j] != mat[i][j]) {
                    return false;
                }
            }
        }

        return true;
    }
};