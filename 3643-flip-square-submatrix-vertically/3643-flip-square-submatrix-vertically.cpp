class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int l = x+k-1;
        for (int i = x; i < x+k && i < l; i++) {
            for (int j = y; j < y+k; j++) {
                swap(grid[i][j], grid[l][j]);
            }
            l--;
        }

        return grid;
    }
};