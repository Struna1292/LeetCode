class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> prefix(nums.size(), 0);
        int currSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            prefix[i] = currSum;
            currSum += nums[i];
        }

        vector<int> output(nums.size(), 0);
        currSum = 0;
        for (int i = nums.size()-1; i >= 0; i--) {
            output[i] = abs(prefix[i] - currSum);
            currSum += nums[i];
        }

        return output;
    }
};