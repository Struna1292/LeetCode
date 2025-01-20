class Solution {
public:
    int subarraySum(vector<int>& nums) {
        
        int output = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = max(0, i-nums[i]); j <= i; j++)
            {
                output += nums[j];
            }
        }

        return output;
    }
};