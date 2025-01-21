class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        
        int max = nums[0];
        int min = nums[0];

        for (int n : nums)
        {
            if (n > max)
            {
                max = n;
            }
            if (n < min)
            {
                min = n;
            }
        }
        
        int output = (max-k)-(min+k);
        if (output < 0)
        {
            return 0;
        }
        
        return output;
    }
};