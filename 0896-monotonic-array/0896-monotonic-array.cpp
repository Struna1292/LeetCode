class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if (nums.size() == 1)
            return true;

        int i = 0;
        while (i+1 < nums.size() && nums[i] == nums[i+1])
        {
            i++;
        }

        if (i+1 == nums.size())
        {
            return true;
        }
        
        if (nums[i] > nums[i+1])
        {
            for (i; i < nums.size()-1; i++)
            {
                if (nums[i] < nums[i+1])
                    return false;
            }
        }
        else
        {
            for (i; i < nums.size()-1; i++)
            {
                if (nums[i] > nums[i+1])
                    return false;
            }
        }
        
        return true;
    }
};