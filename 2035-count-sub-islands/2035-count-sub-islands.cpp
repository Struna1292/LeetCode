class Solution {
public:
    void isSubIsland(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& checkGrid, bool& check) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size() || grid[i][j] == 0) {
            return;
        }

        grid[i][j] = 0;

        if (checkGrid[i][j] == 0) { 
            check = false;
        }
        
        isSubIsland(i+1, j, grid, checkGrid, check);
        isSubIsland(i-1, j, grid, checkGrid, check);
        isSubIsland(i, j+1, grid, checkGrid, check);
        isSubIsland(i, j-1, grid, checkGrid, check);
    }   

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {

        int subIslands = 0;

        for (int i = 0; i < grid2.size(); i++) {
            for (int j = 0; j < grid2[0].size(); j++) {
                if (grid2[i][j] == 1) {
                    bool check = true;
                    isSubIsland(i, j, grid2, grid1, check);

                    if (check) {
                        subIslands++;
                    }
                }
            }
        }

        return subIslands;
    }
};