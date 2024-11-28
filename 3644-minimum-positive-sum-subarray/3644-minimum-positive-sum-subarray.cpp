class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        
        vector<int> prefixSum(nums.size(), 0);

        int curr = 0;

        for (int i = 0; i < prefixSum.size(); i++)
        {
            curr += nums[i];
            prefixSum[i] = curr;
        }

        int output = -1;

        for (int length = l; length <= r; length++)
        {
            for (int i = 0; i <= nums.size()-length; i++)
            {

                int currDiff = 0;
                if (i > 0)
                {
                    currDiff = prefixSum[i+length-1] - prefixSum[i-1];
                }
                else
                {
                    currDiff = prefixSum[i+length-1];
                }

                if (currDiff > 0 && (output == -1 || currDiff < output))
                {
                    output = currDiff;
                }
            }
        }

        return output;
    }
};