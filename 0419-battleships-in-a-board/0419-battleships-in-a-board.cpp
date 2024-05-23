class Solution {
public:

    int countBattleships(vector<vector<char>>& board) {

        int ships = 0;
        
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                if (board[i][j] == 'X')
                {

                    ships++;
                    
                    int k = j;

                    while (j < board[i].size() && board[i][j] == 'X')
                    {
                        board[i][j] = '.';
                        j++;
                    }

                    int l = i+1;

                    while (l < board.size() && board[l][k] == 'X')
                    {
                        board[l][k] = '.';
                        l++;
                    }

                }
            }
        }


        return ships;
    }
};