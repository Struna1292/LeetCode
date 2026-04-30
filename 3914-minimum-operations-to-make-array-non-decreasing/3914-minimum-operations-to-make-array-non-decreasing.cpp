class Solution {
public:
    long long minOperations(vector<int>& nums) {
        long long output = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i-1] > nums[i]) {
                int diff = nums[i-1] - nums[i];
                output += diff;
            }
        }

        return output;
    }
};