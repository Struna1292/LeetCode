class Solution {
public:

    int partitionArray(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));

        int output = 0;

        int i = 0;
        while (i < nums.size())
        {
            output++;
            int index = upper_bound(nums.begin(), nums.end(), nums[i]+k) - nums.begin();
            i = index;
        }

        return output;
    }
};