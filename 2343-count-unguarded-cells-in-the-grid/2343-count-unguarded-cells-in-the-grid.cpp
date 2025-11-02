class Solution {
public:
    void fillLeft(int i, int j, vector<vector<char>>& grid) {
        for (; j >= 0; j--) {
            if (grid[i][j] == 'W' || grid[i][j] == 'G') {
                return;
            }

            grid[i][j] = '-';
        }
    }

    void fillRight(int i, int j, vector<vector<char>>& grid) {
        for (; j < grid[i].size(); j++) {
            if (grid[i][j] == 'W' || grid[i][j] == 'G') {
                return;
            }

            grid[i][j] = '-';
        }
    }

    void fillUp(int i, int j, vector<vector<char>>& grid) {
        for (; i >= 0; i--) {
            if (grid[i][j] == 'W' || grid[i][j] == 'G') {
                return;
            }

            grid[i][j] = '-';
        }        
    }

    void fillDown(int i, int j, vector<vector<char>>& grid) {
        for (; i < grid.size(); i++) {
            if (grid[i][j] == 'W' || grid[i][j] == 'G') {
                return;
            }

            grid[i][j] = '-';
        }
    }

    void fillGrid(int i, int j, vector<vector<char>>& grid) {
        fillLeft(i, j-1, grid);
        fillRight(i, j+1, grid);
        fillUp(i-1, j, grid);
        fillDown(i+1, j, grid);
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<char>> grid(m, vector<char>(n, ' '));

        for (int i = 0; i < walls.size(); i++) {
            grid[walls[i][0]][walls[i][1]] = 'W';
        }

        for (int i = 0; i < guards.size(); i++) {
            grid[guards[i][0]][guards[i][1]] = 'G';
        }

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 'G') {
                    fillGrid(i, j, grid);
                }
            }
        }

        int output = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == ' ') {
                    output++;
                }
            }
        }

        return output;
    }
};