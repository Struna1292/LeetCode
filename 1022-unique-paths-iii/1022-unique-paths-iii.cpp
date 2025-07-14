class Solution {
public:
    void DFS(int i, int j, int steps, vector<vector<int>>& grid, vector<vector<bool>>& seen, int& counter) {

        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size() || grid[i][j] == -1 || seen[i][j]) {
            return;
        }

        if (grid[i][j] == 2) {
            if (steps == -1) {
                counter++;
            }
            return;
        }

        seen[i][j] = true; 

        DFS(i+1, j, steps-1, grid, seen, counter);
        DFS(i-1, j, steps-1, grid, seen, counter);
        DFS(i, j+1, steps-1, grid, seen, counter);
        DFS(i, j-1, steps-1, grid, seen, counter);

        seen[i][j] = false;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int startI = -1;
        int startJ = -1;
        int emptySquares = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                switch (grid[i][j]) {
                    case 0:
                        emptySquares++;
                        break;
                    case 1:
                        startI = i;
                        startJ = j;
                        break;
                }
            }
        }

        vector<vector<bool>> seen(grid.size(), vector<bool>(grid[0].size(), false));
        int pathCounter = 0;

        DFS(startI, startJ, emptySquares, grid, seen, pathCounter);

        return pathCounter;
    }
};