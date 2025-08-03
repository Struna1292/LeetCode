class Solution {
public:
    void DFS(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& seen, bool& isSurrounded) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size()) {
            isSurrounded = false;
            return;
        }
        if (grid[i][j] == 1 || seen[i][j]) {
            return;
        }

        seen[i][j] = true;

        DFS(i+1, j, grid, seen, isSurrounded);
        DFS(i-1, j, grid, seen, isSurrounded);
        DFS(i, j+1, grid, seen, isSurrounded);
        DFS(i, j-1, grid, seen, isSurrounded);
    }

    int closedIsland(vector<vector<int>>& grid) {
        
        vector<vector<bool>> seen(grid.size(), vector<bool>(grid[0].size(), false));
        int closedIslandCounter = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 0 && !seen[i][j]) {
                    bool isSurrounded = true;
                    DFS(i, j, grid, seen, isSurrounded);

                    if (isSurrounded) {
                        closedIslandCounter++;
                    }
                }
            }
        }

        return closedIslandCounter;
    }
};