class Solution {
public:
    vector<vector<int>> directions = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}
    };

    void fillAroundCell(const vector<int>& curr, queue<vector<int>>& que, int& emptyCells, vector<vector<int>>& grid, vector<vector<bool>>& visited, list<vector<int>>& currentlyVisited) {
        const int& row = curr[0];
        const int& col = curr[1];

        const int& color = curr[2];

        for (int i = 0; i < directions.size(); i++) {
            int nextRow = row + directions[i][0];
            int nextCol = col + directions[i][1];

            if (nextRow < 0 || nextRow >= grid.size() ||
                nextCol < 0 || nextCol >= grid[0].size() ||
                visited[nextRow][nextCol]) {
                continue;
            }

            if (grid[nextRow][nextCol] == 0) {
                emptyCells--;
            }

            if (color > grid[nextRow][nextCol]) {
                grid[nextRow][nextCol] = color;
                que.push({nextRow, nextCol, color});
                currentlyVisited.push_back({nextRow, nextCol});
            }
        }
    }

    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>> grid(n, vector<int>(m, 0));
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        int emptyCells = n * m;
        queue<vector<int>> que; 

        for (int i = 0; i < sources.size(); i++) {
            int row = sources[i][0];
            int col = sources[i][1];

            int color = sources[i][2];

            if (grid[row][col] == 0) {
                emptyCells--;
            }

            grid[row][col] = max(grid[row][col], color);
            que.push({row, col, color});
            visited[row][col] = true;
        }

        
        while (!que.empty() && emptyCells > 0) {

            list<vector<int>> currentlyVisited;

            int size = que.size();
            while (size > 0) {
                size--;

                vector<int> curr = que.front();
                que.pop();

                const int& row = curr[0];
                const int& col = curr[1];
                const int& color = curr[2];

                if (color != grid[row][col]) {
                    continue;
                }

                fillAroundCell(curr, que, emptyCells, grid, visited, currentlyVisited);
            }

            while (!currentlyVisited.empty()) {
                vector<int> curr = currentlyVisited.back();
                currentlyVisited.pop_back();

                visited[curr[0]][curr[1]] = true;
            }
        }

        return grid;
    }
};