class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {

        if (k == 1)
        {
            return true;
        }
        
        int counter = 1;

        int index = -1;

        for (int i = nums.size()-2; i >= 0; i--)
        {
            if (nums[i] < nums[i+1])
            {
                counter++;
                if (counter == 2*k)
                {
                    return true;
                }
                else if (counter >= k)
                {
                    if (index != -1 && index - i == k)
                    {
                        return true;
                    }
                    index = i;
                }
            }
            else
            {
                counter = 1;
            }
        }

        return false;
    }
};