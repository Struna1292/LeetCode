class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                int ignore = grid.size()-1-i;
                if (i == j)
                {
                    if (grid[i][j] == 0 || grid[i][grid.size()-1-i] == 0)
                    {
                        return false;
                    }
                }
                else if (grid[i][j] != 0 && j != ignore)
                {
                    return false;
                }
            }
        }
        

        return true;
    }
};