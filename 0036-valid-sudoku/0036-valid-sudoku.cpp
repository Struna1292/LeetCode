class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        vector<vector<bool>> columns(board.size(), vector<bool>(9, false));

        vector<vector<vector<bool>>> grids(3, vector<vector<bool>>(3, vector<bool>(9, false)));

        for (int i = 0; i < board.size(); i++)
        {

            bool nums[9] = { false };
            for (int j = 0; j < board[i].size(); j++)
            {
                if (board[i][j] != '.')
                {
                    // row validation
                    if (nums[board[i][j]-1-'0'])
                    {
                        return false;
                    }
                    else
                    {
                        nums[board[i][j]-1-'0'] = true;
                    }


                    // column validation
                    if (columns[j][board[i][j]-1-'0'])
                    {
                        return false;
                    }
                    else
                    {
                        columns[j][board[i][j]-1-'0'] = true;
                    }

                    // 3x3 grid validation
                    if (grids[i/3][j/3][board[i][j]-1-'0'])
                    {
                        return false;
                    }
                    else
                    {
                        grids[i/3][j/3][board[i][j]-1-'0'] = true;
                    }
                }

            }
        }


        return true;
    }
};