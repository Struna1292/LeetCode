class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if (k == 1) {
            return 0;
        }
        k--;

        sort(begin(nums), end(nums), greater<int>());
        int output = nums[0] - nums[k];

        for (int i = 0; i+k < nums.size(); i++) {
            if (output > nums[i] - nums[i+k]) {
                output = nums[i] - nums[i+k];
            }
        }

        return output;
    }
};