class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        
        int output = 0;
        int counter = 0;

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > nums[i-1])
            {
                counter++;
            }
            else
            {
                if (output < counter)
                {
                    output = counter;
                }
                counter = 0;
            }
        }
        if (output < counter)
        {
            output = counter;
        }

        return output+1;
    }
};