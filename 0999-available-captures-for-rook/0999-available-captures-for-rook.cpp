class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {

        int row = -1;
        int col = -1;
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (board[i][j] == 'R')
                {
                    row = i;
                    col = j;
                    break;
                }
            }
            if (row != -1)
            {
                break;
            }
        }

        int counter = 0;

        // check up
        for (int i = row; i >= 0; i--)
        {
            if (board[i][col] == 'p')
            {
                counter++;
                break;
            }
            else if (board[i][col] == 'B')
            {
                break;
            }
        }

        // check down
        for (int i = row; i < 8; i++)
        {
            if (board[i][col] == 'p')
            {
                counter++;
                break;
            }
            else if (board[i][col] == 'B')
            {
                break;
            }
        }

        // check left
        for (int i = col; i < 8; i++)
        {
            if (board[row][i] == 'p')
            {
                counter++;
                break;
            }
            else if (board[row][i] == 'B')
            {
                break;
            }
        }

        // check right
        for (int i = col; i >= 0; i--)
        {
            if (board[row][i] == 'p')
            {
                counter++;
                break;
            }
            else if (board[row][i] == 'B')
            {
                break;
            }
        }

        return counter;
    }
};