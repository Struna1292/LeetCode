class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        
        vector<int> output;

        for (int i = 0; i < grid.size(); i++)
        {
            if (i % 2 == 0)
            {
                for (int j = 0; j < grid[i].size(); j+=2)
                {
                    output.push_back(grid[i][j]);
                }
            }
            else
            {
                if (grid[i].size() % 2 == 0)
                {
                    for (int j = grid[i].size()-1; j >= 0; j-=2)
                    {
                        output.push_back(grid[i][j]);
                    }
                }
                else
                {
                    for (int j = grid[i].size()-2; j >= 0; j-=2)
                    {
                        output.push_back(grid[i][j]);
                    }
                }
            }
        }

        return output;
    }
};