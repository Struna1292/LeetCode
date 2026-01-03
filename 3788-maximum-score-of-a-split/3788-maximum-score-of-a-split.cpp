class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        vector<int> suffixMin(nums.size(), 0);

        int currMin = nums[nums.size()-1];
        for (int i = nums.size()-1; i >= 0; i--) {
            if (currMin > nums[i]) {
                currMin = nums[i];
            }

            suffixMin[i] = currMin;
        }

        long long currSum = 0;
        long long output = INT_MIN;
        for (int i = 0; i < nums.size()-1; i++) {
            currSum += nums[i];

            if (output < currSum - suffixMin[i+1]) {
                output = currSum - suffixMin[i+1];
            }
        }

        return output;
    }
};