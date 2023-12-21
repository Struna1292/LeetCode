class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> output(2, 0);

        int end = grid.size() * grid.size();

        vector<bool> nums(end, false);


        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (nums[grid[i][j]-1])
                {
                    output[0] = grid[i][j];
                }
                nums[grid[i][j]-1] = true;
            }
        }

        for (int i = 0; i < end; i++)
        {
            if (!nums[i])
            {
                output[1] = i+1;
                break;
            }
        }

        return output;
    }
};