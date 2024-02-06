class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        vector<int> sums;

        for (int i = 1; i < nums.size(); i++)
        {
            sums.push_back(nums[i-1]+nums[i]);
        }

        sort(begin(sums), end(sums));

        for (int i = 1; i < sums.size(); i++)
        {
            if (sums[i-1] == sums[i])
            {
                return true;
            }
        }

        return false;
    }
};