class Solution {
public:
    char getOpposite(char dir) {
        if (dir == 'u') return 'd';
        if (dir == 'd') return 'u';
        if (dir == 'l') return 'r';
        if (dir == 'r') return 'l';
        return ' ';
    }

    bool walkToEnd(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& visited, unordered_map<int, string>& streets) {
        if (i == grid.size() - 1 && j == grid[0].size() - 1) {
            return true;
        }

        visited[i][j] = true;
        string currentDirs = streets[grid[i][j]];

        for (char dir : currentDirs) {
            int ni = i, nj = j;
            
            if (dir == 'u') ni--;
            else if (dir == 'd') ni++;
            else if (dir == 'l') nj--;
            else if (dir == 'r') nj++;

            if (ni >= 0 && ni < grid.size() && nj >= 0 && nj < grid[0].size() && !visited[ni][nj]) {
                
                char requiredEntry = getOpposite(dir);
                string nextCellDirs = streets[grid[ni][nj]];

                if (nextCellDirs.find(requiredEntry) != string::npos) {
                    if (walkToEnd(ni, nj, grid, visited, streets)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }

    bool hasValidPath(vector<vector<int>>& grid) {
        unordered_map<int, string> streets = {
            {1, "lr"}, {2, "ud"}, {3, "ld"}, 
            {4, "dr"}, {5, "lu"}, {6, "ur"}
        };

        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        return walkToEnd(0, 0, grid, visited, streets);
    }
};