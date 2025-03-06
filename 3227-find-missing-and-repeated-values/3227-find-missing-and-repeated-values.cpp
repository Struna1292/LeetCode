class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int size = grid.size() * grid.size();

        vector<int> nums(size, 0);

        for (vector<int> curr : grid)
        {
            for (int n : curr)
            {
                nums[n-1]++;
            }
        }

        int a = -1;
        int b = -1;

        for (int i = 0; i < size; i++)
        {
            if (nums[i] == 2)
            {
                a = i+1;
            }
            else if (nums[i] == 0)
            {
                b = i+1;
            }
        }

        return {a,b};
    }
};