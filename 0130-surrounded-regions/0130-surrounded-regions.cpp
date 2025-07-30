class Solution {
public:
    bool isEdge(int& i, int& j, vector<vector<char>>& grid) {
        if (i == 0 || i+1 == grid.size() || j == 0 || j+1 == grid[i].size()) {
            return true;
        }
        return false;
    }

    void DFS(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& seen, bool& isSurrounded) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size() || seen[i][j] || grid[i][j] == 'X') {
            return;
        }

        if (isEdge(i, j, grid)) {
            isSurrounded = false;
        }

        seen[i][j] = true;

        DFS(i+1, j, grid, seen, isSurrounded);
        DFS(i-1, j, grid, seen, isSurrounded);
        DFS(i, j+1, grid, seen, isSurrounded);
        DFS(i, j-1, grid, seen, isSurrounded);
    }

    void replaceDFS(int i, int j, vector<vector<char>>& grid) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size() || grid[i][j] == 'X') {
            return;
        }

        grid[i][j] = 'X';

        replaceDFS(i+1, j, grid);
        replaceDFS(i-1, j, grid);
        replaceDFS(i, j+1, grid);
        replaceDFS(i, j-1, grid);
    } 

    void solve(vector<vector<char>>& board) {
        vector<vector<bool>> seen(board.size(), vector<bool>(board[0].size(), false));

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == 'O' && !seen[i][j]) {
                    bool isSurrounded = true;

                    DFS(i, j, board, seen, isSurrounded);

                    if (isSurrounded) {
                        replaceDFS(i, j, board);
                    }
                }
            }
        }

        return;
    }
};