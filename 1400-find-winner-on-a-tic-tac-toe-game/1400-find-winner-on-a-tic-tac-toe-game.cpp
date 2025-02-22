class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<char>> grid(3, vector<char>(3, ' '));

        for (int i = 0; i < moves.size(); i++)
        {
            if ((i+2) % 2 == 0)
            {
                grid[moves[i][0]][moves[i][1]] = 'X';
            }
            else
            {
                grid[moves[i][0]][moves[i][1]] = 'O';
            }
        }
        
        for (int i = 0; i < grid.size(); i++)
        {   
            // check rows
            if (grid[i][0] != ' ' && grid[i][0] == grid[i][1] && grid[i][0] == grid[i][2])
            {
                if (grid[i][0] == 'X')
                {
                    return "A";
                }
                else
                {
                    return "B";
                }
            }

            //check cols
            if (grid[0][i] != ' ' && grid[0][i] == grid[1][i] && grid[0][i] == grid[2][i])
            {
                if (grid[0][i] == 'X')
                {
                    return "A";
                }
                else
                {
                    return "B";
                }
            }
        }

        // first diagonal
        if (grid[0][0] != ' ' && grid[0][0] == grid[1][1] && grid[0][0] == grid[2][2])
        {
            if (grid[0][0] == 'X')
            {
                return "A";
            }
            else
            {
                return "B";
            }
        }

        // second diagonal

        if (grid[2][0] != ' ' && grid[2][0] == grid[1][1] && grid[2][0] == grid[0][2])
        {
            if (grid[2][0] == 'X')
            {
                return "A";
            }
            else
            {
                return "B";
            }
        }

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == ' ')
                {   
                    return "Pending";
                }
            }
        }

        return "Draw";
    }
};