class Solution {
public:
    int livingNeighbors(int i, int j, vector<vector<int>>& board) {

        vector<vector<int>> directions = {
            {-1, 0}, // up
            {-1, 1}, 
            {0, 1}, // right
            {1, 1},
            {1, 0}, // down
            {1, -1},
            {0, -1}, // left
            {-1, -1}
        };

        int livingCount = 0;

        for (int index = 0; index < directions.size(); index++) {
            int currI = i + directions[index][0];
            int currJ = j + directions[index][1];

            if (currI < 0 || currI >= board.size() || currJ < 0 || currJ >= board[currI].size() || board[currI][currJ] == 0) {
                continue;
            }

            livingCount++;
        }

        return livingCount;
    }

    void gameOfLife(vector<vector<int>>& board) {
        
        vector<vector<int>> boardCopy = board;

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                int currLivingNeighbors = livingNeighbors(i, j, boardCopy);

                if (board[i][j] == 0) {
                    if (currLivingNeighbors == 3) {
                        board[i][j] = 1;
                    }
                }
                else {
                    if (currLivingNeighbors == 0 || currLivingNeighbors == 1 || currLivingNeighbors >= 4) {
                        board[i][j] = 0;
                    }
                }
            }
        }
    }
};