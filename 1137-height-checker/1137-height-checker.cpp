class Solution {
public:
    int heightChecker(vector<int>& heights) {
        
        vector<int> nums = heights;

        sort(begin(nums), end(nums));

        int output = 0;

        for (int i = 0; i < heights.size(); i++)
        {
            if (heights[i] != nums[i])
            {
                output++;
            }
        }

        return output;
    }
};