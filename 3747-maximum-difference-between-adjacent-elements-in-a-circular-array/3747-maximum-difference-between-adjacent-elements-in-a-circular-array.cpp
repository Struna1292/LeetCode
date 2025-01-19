class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        
        int output = 0;

        for (int i = 1; i < nums.size(); i++)
        {
            if (abs(nums[i]-nums[i-1]) > output)
            {
                output = abs(nums[i]-nums[i-1]);
            }
        }
        if (abs(nums[0]-nums[nums.size()-1]) > output)
        {
            output = abs(nums[0]-nums[nums.size()-1]);
        }

        return output;
    }
};