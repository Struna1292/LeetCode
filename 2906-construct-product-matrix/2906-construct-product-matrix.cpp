class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        vector<vector<int>> prefixRowGrid(grid.size(), vector<int>(grid[0].size()+1, 1));
        vector<vector<int>> suffixRowGrid = prefixRowGrid;
        int modulo = 12345;

        long long curr = 1;

        for (int i = 0; i < grid.size(); i++) {
            curr = 1;
            for (int j = 0; j < grid[i].size(); j++) {
                curr *= grid[i][j];
                curr %= modulo;

                prefixRowGrid[i][j+1] = curr;
            }

            curr = 1;
            for (int j = grid[i].size()-1; j >= 0; j--) {
                curr *= grid[i][j];
                curr %= modulo;

                suffixRowGrid[i][j] = curr;
            }
        }

        vector<int> prefixColGrid(grid.size()+1, 1);
        vector<int> suffixColGrid = prefixColGrid;

        curr = 1;
        for (int i = 0; i < grid.size(); i++) {
            curr *= prefixRowGrid[i][prefixRowGrid[0].size()-1];
            curr %= modulo;

            prefixColGrid[i+1] = curr;
        }

        curr = 1;
        for (int i = grid.size()-1; i >= 0; i--) {
            curr *= prefixRowGrid[i][prefixRowGrid[0].size()-1];
            curr %= modulo;

            suffixColGrid[i] = curr;
        }


        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                long long row = (prefixRowGrid[i][j] * suffixRowGrid[i][j+1]) % modulo;
                long long col = (prefixColGrid[i] * suffixColGrid[i+1]) % modulo;

                grid[i][j] = (row * col) % modulo;
            }
        }    

        return grid;
    }
};