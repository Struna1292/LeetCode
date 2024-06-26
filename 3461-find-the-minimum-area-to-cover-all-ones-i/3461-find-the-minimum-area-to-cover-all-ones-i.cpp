class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        
        // to calculate area of rectangle we need length of side a and b
        // a length is difference between rows from first 1 occurrence and last
        // b length is difference between columns from first 1 occurence and last

        int up = -1;
        int down = -1;
        int left = -1;
        int right = -1;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    if (up == -1)
                    {
                        up = i;
                    }
                    
                    if (down == -1 || down < i)
                    {
                        down = i;
                    }

                    if (left == -1 || left > j)
                    {
                        left = j;
                    }

                    if (right == -1 || right < j)
                    {
                        right = j;
                    }
                }
            }
        }

        return (down - up + 1) * (right - left + 1);
    }
};