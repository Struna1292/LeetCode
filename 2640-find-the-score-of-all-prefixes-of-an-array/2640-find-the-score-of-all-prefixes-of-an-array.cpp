class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {

        vector<long long> output(nums.size(), 0);

        long long prev = 0;
        long long currMax = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > currMax)
            {
                currMax = nums[i];
            }
            prev += (nums[i] + currMax);
            output[i] = prev;
        }

        return output;
    }
};