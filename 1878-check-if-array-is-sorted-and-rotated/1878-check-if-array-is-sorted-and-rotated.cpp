class Solution {
public:
    bool check(vector<int>& nums) {

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i-1] > nums[i])
            {
                for (int j = 1; j < nums.size(); j++)
                {
                    if (nums[(i+j-1)%nums.size()] > nums[(i+j)%nums.size()])
                    {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};