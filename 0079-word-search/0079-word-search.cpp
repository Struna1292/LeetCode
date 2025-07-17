class Solution {
public:
    bool containsWord(int i, int j, string& word, int currIndex, 
        vector<vector<char>>& board, vector<vector<bool>>& seen) {
            
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() 
            || seen[i][j] || board[i][j] != word[currIndex]) {
            return false;
        }

        seen[i][j] = true;

        if (currIndex+1 == word.length()) {
            return true;
        }

        bool check = containsWord(i+1, j, word, currIndex+1, board, seen)
            || containsWord(i-1, j, word, currIndex+1, board, seen)
            || containsWord(i, j+1, word, currIndex+1, board, seen)
            || containsWord(i, j-1, word, currIndex+1, board, seen);

        seen[i][j] = false;

        return check;
    }

    bool exist(vector<vector<char>>& board, string word) {

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == word[0]) {
                    vector<vector<bool>> seen(board.size(), vector<bool>(board[0].size(), false));
                    if (containsWord(i, j, word, 0, board, seen)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};