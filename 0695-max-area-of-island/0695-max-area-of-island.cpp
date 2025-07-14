class Solution {
public:
    void DFS(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& seen, int& area) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size() || seen[i][j] || grid[i][j] == 0) { 
            return;
        }

        area++;
        seen[i][j] = true;

        DFS(i+1, j, grid, seen, area);
        DFS(i-1, j, grid, seen, area);
        DFS(i, j+1, grid, seen, area);
        DFS(i, j-1, grid, seen, area);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        vector<vector<bool>> seen(grid.size(), vector<bool>(grid[0].size(), false));

        int maxArea = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1 && !seen[i][j]) {
                    int currArea = 0;
                    DFS(i, j, grid, seen, currArea);

                    maxArea = max(currArea, maxArea);
                }
            }
        }

        return maxArea;
    }
};