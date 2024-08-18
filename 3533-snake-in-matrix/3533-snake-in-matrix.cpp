class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        
        vector<vector<int>> grid(n, vector<int>(n, 0));

        int counter = 0;
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                grid[i][j] = counter;
                counter++;
            }
        }

        int i = 0;
        int j = 0;

        for (string command : commands)
        {
            if (command == "UP")
            {
                i--;
            }
            else if (command == "DOWN")
            {
                i++;
            }
            else if (command == "LEFT")
            {
                j--;
            }
            else if (command == "RIGHT")
            {
                j++;
            }
        }

        return grid[i][j];
    }
};