class Solution {
public:
    int sumOfGoodNumbers(vector<int>& nums, int k) {
        
        int output = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if ((i-k < 0 || nums[i-k] < nums[i]) && (i+k >= nums.size() || nums[i+k] < nums[i]))
            {
                output += nums[i];
            }
        }

        return output;
    }
};