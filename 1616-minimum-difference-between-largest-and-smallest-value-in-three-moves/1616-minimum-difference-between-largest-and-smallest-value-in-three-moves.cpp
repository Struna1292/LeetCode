class Solution {
public:
    int minDifference(vector<int>& nums) {

        if (nums.size() <= 4)
        {
            return 0;
        }

        sort(begin(nums), end(nums));

        // we have only 4 combinations of changing numbers
        // 3 left 0 right
        // 2 left 1 right
        // 1 left 2 right
        // 0 left 3 right

        int output = nums[nums.size()-1] - nums[3]; // 3 left 0 right

        if (nums[nums.size()-2] - nums[2] < output) // 2 left 1 right
        {
            output = nums[nums.size()-2] - nums[2];
        }

        if (nums[nums.size()-3] - nums[1] < output) // 1 left 2 right
        {
            output = nums[nums.size()-3] - nums[1];
        }

        if (nums[nums.size()-4] - nums[0] < output) // 0 left 3 right
        {
            output = nums[nums.size()-4] - nums[0];
        }

        return output;
    }
};