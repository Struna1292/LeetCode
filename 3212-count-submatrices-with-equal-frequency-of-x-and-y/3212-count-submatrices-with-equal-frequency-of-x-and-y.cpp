class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        
        vector<vector<int>> yGrid(grid.size(), vector<int>(grid[0].size(), 0));
        vector<vector<int>> xGrid(grid.size(), vector<int>(grid[0].size(), 0));
        
        for (int i = 0; i < grid.size(); i++) {
            int currY = 0;
            int currX = 0;
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 'Y') {
                    currY++;
                }
                else if (grid[i][j] == 'X') {
                    currX++;
                }
                yGrid[i][j] = currY;
                xGrid[i][j] = currX;
            }
        }

        for (int i = 0; i < grid[0].size(); i++) {
            int currY = 0;
            int currX = 0;
            for (int j = 0; j < grid.size(); j++) {
                currY += yGrid[j][i];
                yGrid[j][i] = currY;

                currX += xGrid[j][i];
                xGrid[j][i] = currX;
            }
        }

        int output = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (xGrid[i][j] > 0 && xGrid[i][j] == yGrid[i][j]) {
                    output++;
                }
            }
        }

        return output;
    }
};