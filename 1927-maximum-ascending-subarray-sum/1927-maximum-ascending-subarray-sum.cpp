class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        
        int output = nums[0];
        int curr = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > output)
            {
                output = nums[i];
            }
            if (nums[i] > nums[i-1])
            {
                curr += nums[i];
                if (curr > output)
                {
                    output = curr;
                }
            }
            else
            {
                curr = nums[i];
            }
        }

        return output;
    }
};