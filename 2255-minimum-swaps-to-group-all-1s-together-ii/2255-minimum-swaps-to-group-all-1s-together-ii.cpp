class Solution {
public:
    int minSwaps(vector<int>& nums) {
        
        int windowSize = 0;

        for (int x : nums)
        {
            if (x == 1)
            {
                windowSize++;
            }
        }

        int minZeros = 0;

        for (int i = 0; i < windowSize; i++)
        {
            if (nums[i] == 0)
            {
                minZeros++;
            }
        }

        int j = windowSize;

        int output = minZeros;

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[(j - windowSize) % nums.size()] == 0)
            {
                minZeros--;
            }

            if (nums[j % nums.size()] == 0)
            {
                minZeros++;
            }

            if (minZeros < output)
            {
                output = minZeros;
            }

            j++;
        }

        return output;
    }
};