class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        
        int lowest = nums[0];
        int highest = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            lowest = min(lowest, nums[i]);
            highest = max(highest, nums[i]);
        }

        return (long long)(highest - lowest) * (long long)k;
    }
};