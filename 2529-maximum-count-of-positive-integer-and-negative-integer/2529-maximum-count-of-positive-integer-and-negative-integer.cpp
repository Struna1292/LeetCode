class Solution {
public:
    int maximumCount(vector<int>& nums) {
    
        if (nums[0] > 0 && nums[nums.size()-1] > 0 || nums[0] < 0 && nums[nums.size()-1] < 0)
        {
            return nums.size();
        }
        
        int zeros = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                zeros++;
            }
            else if (nums[i] > 0)
            {
                if (i-zeros > nums.size()-i)
                {
                    return i-zeros;
                }
                else
                {
                    return nums.size()-i;
                }
            }
        }

        return 0;
    }
};