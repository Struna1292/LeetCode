class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));

        int minSum = 0;
        for (int i = 0; i < k; i++) {
            minSum += nums[i];
        }

        int maxSum = 0;
        for (int i = nums.size()-k; i < nums.size(); i++) {
            maxSum += nums[i];
        }

        return abs(minSum - maxSum);
    }
};