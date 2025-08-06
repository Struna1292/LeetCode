class Solution {
public:
    void DFS(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& seen, int& target, int& newValue) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size() || seen[i][j] || grid[i][j] != target) {
            return;
        }

        grid[i][j] = newValue;
        seen[i][j] = true;

        DFS(i+1, j, grid, seen, target, newValue);
        DFS(i-1, j, grid, seen, target, newValue);
        DFS(i, j+1, grid, seen, target, newValue);
        DFS(i, j-1, grid, seen, target, newValue);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int target = image[sr][sc];
        vector<vector<bool>> seen(image.size(), vector<bool>(image[0].size(), false));

        DFS(sr, sc, image, seen, target, color);
        return image;
    }
};