class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        
        int counterZeros = 0;
        int counterOnes = 0;

        for (int n : nums)
        {
            if (n % 2 == 0)
            {
                counterZeros++;
            }
            else
            {
                counterOnes++;
            }
        }

        for (int i = 0; i < counterZeros; i++)
        {
            nums[i] = 0;
        }

        int i = nums.size()-1;
        while (counterOnes > 0)
        {
            nums[i] = 1;

            counterOnes--;
            i--;
        }

        return nums;
    }
};