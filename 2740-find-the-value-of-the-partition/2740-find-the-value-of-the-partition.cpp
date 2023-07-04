class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {

        sort(begin(nums), end(nums));

        int output = nums[1] - nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] - nums[i-1] < output)
            {
                output = nums[i] - nums[i-1];
            }
        }

        return output;
    }
};