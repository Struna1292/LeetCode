class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] >= k)
            {
                return 1;
            }
        }
        
        for (int length = 2; length <= nums.size(); length++)
        {
            for (int i = 0; i < nums.size(); i++)
            {
                if (i + length <= nums.size())
                {
                    int curr = nums[i];
                    for (int j = i; j < i+length-1; j++)
                    {
                        curr = curr | nums[j+1];
                        if (curr >= k)
                        {
                            return length;
                        }
                    }
                }
            }
        }
        
        return -1;
    }
};