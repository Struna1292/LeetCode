class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        
        vector<long long> prefixSum(nums.size(), 0);

        long long curr = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            curr += nums[i];
            prefixSum[i] = curr;
        }

        int output = 0;

        for (int i = 0; i < nums.size()-1; i++)
        {
            if (prefixSum[i] >= curr - prefixSum[i])
            {
                output++;
            }
        }

        return output;
    }
};