class Solution {
public:
    void DFS(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& seen, int& perimeter) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size() || grid[i][j] == 0) {
            perimeter++; 
            return;
        }

        if (seen[i][j]) {
            return;
        }

        seen[i][j] = true;

        DFS(i+1, j, grid, seen, perimeter);
        DFS(i-1, j, grid, seen, perimeter);
        DFS(i, j+1, grid, seen, perimeter);
        DFS(i, j-1, grid, seen, perimeter);
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        // notice that with DFS when we go to invalid coordinates that makes perimeter++

        vector<vector<bool>> seen(grid.size(), vector<bool>(grid[0].size(), false));

        int perimeter = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1 && !seen[i][j]) {
                    DFS(i, j, grid, seen, perimeter);
                }
            }
        }

        return perimeter;
    }
};