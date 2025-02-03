class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int increasingCounter = 1;
        int decreasingCounter = 1;

        int longest = 1;

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i-1] > nums[i])
            {
                decreasingCounter++;
                increasingCounter = 1;
            }
            else if (nums[i-1] < nums[i])
            {
                decreasingCounter = 1;
                increasingCounter++;
            }
            else
            {
                decreasingCounter = 1;
                increasingCounter = 1;
            }

            if (increasingCounter > longest)
            {
                longest = increasingCounter;
            }
            else if (decreasingCounter > longest)
            {
                longest = decreasingCounter;
            }
        }

        return longest;
    }
};