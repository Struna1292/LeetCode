class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        
        sort(begin(nums), end(nums));

        long long output = 0;

        for (int i = 0; i < nums.size()-1; i++)
        {
            auto left = lower_bound(begin(nums)+1+i, end(nums), (lower - nums[i]));
            auto right = upper_bound(begin(nums)+1+i, end(nums), (upper - nums[i]));

            output += right - left;
        }

        return output;
    }   
};