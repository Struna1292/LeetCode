class Solution {
public:
    void DFS(int i, int j, vector<vector<char>>& grid) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size() || grid[i][j] == '0') {
            return;
        }

        grid[i][j] = '0';

        DFS(i+1, j, grid);
        DFS(i-1, j, grid);
        DFS(i, j+1, grid);
        DFS(i, j-1, grid);
    }

    int numIslands(vector<vector<char>>& grid) {
        int islandCounter = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1') {
                    islandCounter++;
                    DFS(i, j, grid);
                }
            }
        }

        return islandCounter;
    }
};