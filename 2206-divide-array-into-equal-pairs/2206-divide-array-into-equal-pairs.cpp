class Solution {
public:
    bool divideArray(vector<int>& nums) {
        
        sort(begin(nums), end(nums));

        int prev = nums[0];
        int counter = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != prev)
            {
                if (counter % 2 != 0)
                {
                    return false;
                }
                prev = nums[i];
                counter = 1;
            }
            else
            {
                counter++;
            }
        }

        if (counter % 2 != 0)
        {
            return false;
        }
        return true;
    }
};