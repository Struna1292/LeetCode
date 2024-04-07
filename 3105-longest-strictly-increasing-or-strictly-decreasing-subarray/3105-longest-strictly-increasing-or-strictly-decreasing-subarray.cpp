class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        
        int output = 1;

        int prev = nums[0];

        int counter = 1;

        for (int i = 1; i < nums.size(); i++)
        {
            if (prev < nums[i])
            {
                counter++;
                if (counter > output)
                {
                    output = counter;
                }
            }
            else
            {
                counter = 1;
            }
            prev = nums[i];
        }

        prev = nums[0];
        counter = 1;

        for (int i = 1; i < nums.size(); i++)
        {
            if (prev > nums[i])
            {
                counter++;
                if (counter > output)
                {
                    output = counter;
                }
            }
            else
            {
                counter = 1;
            }
            prev = nums[i];
        }

        return output;
    }
};