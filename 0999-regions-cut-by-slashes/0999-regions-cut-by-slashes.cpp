class Solution {
public:
    void paintOnes(int i, int j, char c, vector<vector<int>>& grid) {
        if (c == '/') {
            int indexJ = 3;
            for (int indexI = 0; indexI < 4; indexI++) {
                grid[i+indexI][j+indexJ] = 1;
                indexJ--;
            }            
        }
        else if (c == '\\') {
            for (int index = 0; index < 4; index++) {
                grid[i+index][j+index] = 1;
            }
        }
    }

    void DFS(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& directions) {
        if (i < 0 || i >= grid.size() ||
            j < 0 || j >= grid[i].size() || grid[i][j] == 1) {
            return;
        }

        grid[i][j] = 1;

        for (int k = 0; k < directions.size(); k++) {
            DFS(i+directions[k][0], j+directions[k][1], grid, directions);
        }
    }

    int regionsBySlashes(vector<string>& regions) {
        // 4x4 is the minimum size to represent diagonal with staircase between /
        // every next subgrid needs to overlap so it has 3 rows not 4
        // thus total number of rows and cols is regions.size()*3+1

        vector<vector<int>> grid(regions.size()*3+1, vector<int>(regions.size()*3+1, 0));

        int index = 0;
        for (int i = 0; i < regions.size(); i++) {
            for (int j = 0; j < regions[i].size(); j++) {
                paintOnes(i*3, j*3, regions[i][j], grid);
            }
        }

        vector<vector<int>> directions = {
            {-1, 0}, // up
            {0, 1}, // right
            {1, 0}, // down
            {0, -1}, // left
        };

        int output = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 0) {
                    DFS(i, j, grid, directions);
                    output++;
                }
            }
        }

        return output;
    }
};