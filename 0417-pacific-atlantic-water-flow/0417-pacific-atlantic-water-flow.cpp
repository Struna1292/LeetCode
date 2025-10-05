class Solution {
public:
    void DFS(int i, int j, int prev, vector<vector<int>>& grid, vector<vector<bool>>& seen) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[i].size() || grid[i][j] < prev || seen[i][j]) {
            return;
        }

        seen[i][j] = true;

        DFS(i, j-1, grid[i][j], grid, seen);
        DFS(i, j+1, grid[i][j], grid, seen);
        DFS(i-1, j, grid[i][j], grid, seen);
        DFS(i+1, j, grid[i][j], grid, seen);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        // 0 - not iterated, 1 - true, 2 - false, 3 - current iteration
        vector<vector<bool>> pacific(heights.size(), vector<bool>(heights[0].size(), false));
        vector<vector<bool>> atlantic(heights.size(), vector<bool>(heights[0].size(), false));

        vector<vector<int>> output;

        // first column
        for (int i = 0; i < heights.size(); i++) {
            DFS(i, 0, -1, heights, pacific);
        }

        // first row
        for (int i = 0; i < heights[0].size(); i++) {
            DFS(0, i, -1, heights, pacific);
        }

        // last column
        for (int i = 0; i < heights.size(); i++) {
            DFS(i, heights[0].size()-1, -1, heights, atlantic);
        }

        // last row
        for (int i = 0; i < heights[0].size(); i++) {
            DFS(heights.size()-1, i, -1, heights, atlantic);
        }

        for (int i = 0; i < heights.size(); i++) {
            for (int j = 0; j < heights[i].size(); j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    output.push_back({i, j});
                }
            }
        }

        return output;
    }
};