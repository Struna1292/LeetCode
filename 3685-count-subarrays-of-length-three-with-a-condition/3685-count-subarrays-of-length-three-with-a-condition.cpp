class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        
        int output = 0;
        
        for (int i = 1; i < nums.size()-1; i++)
        {
            if ((nums[i-1] + nums[i+1])*2 == nums[i])
            {
                output++;
            }
        }

        return output;
    }
};