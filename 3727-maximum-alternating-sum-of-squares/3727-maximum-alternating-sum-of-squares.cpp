class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            nums[i] *= nums[i];
        }

        sort(begin(nums), end(nums));

        long long output = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i < nums.size() / 2) {
                output -= nums[i];
            }
            else {
                output += nums[i];
            }
        }

        return output;
    }
};