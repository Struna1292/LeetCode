class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        sort(begin(nums), end(nums), greater<int>());

        long long output = 0;
        for (int i = 1; i < (nums.size() / 3) * 2; i+=2) {
            output += nums[i];
        }

        return output;
    }
};