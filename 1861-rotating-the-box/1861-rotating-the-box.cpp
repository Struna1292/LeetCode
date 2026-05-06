class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {

        int m = box.size();
        int n = box[0].size();

        vector<vector<char>> output(n, vector<char>(m, '.'));

        for (int i = 0; i < m; i++) {

            int drop = n - 1; 

            for (int j = n - 1; j >= 0; j--) {

                if (box[i][j] == '*') {
                    output[j][m - 1 - i] = '*';
                    drop = j - 1; 
                }
                else if (box[i][j] == '#') {
                    output[drop][m - 1 - i] = '#';
                    drop--;
                }
            }
        }

        return output;
    }
};