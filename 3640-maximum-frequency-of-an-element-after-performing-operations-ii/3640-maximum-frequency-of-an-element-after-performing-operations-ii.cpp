class Solution {
public:
    int helper(vector<int>& nums, long long val, int& k, int numOperations, int counter) {
        auto left = upper_bound(begin(nums), end(nums), val - k - 1);
        auto right = upper_bound(begin(nums), end(nums), val + k) - 1;

        int numsInRange = right - left + 1;

        int possibleNumbersToChange = numsInRange - counter;

        if (possibleNumbersToChange > numOperations) {
            return numOperations + counter;
        }

        return possibleNumbersToChange + counter;
    }

    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        
        sort(begin(nums), end(nums));

        int output = 0;
        int prev = nums[0];
        int counter = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == prev) {
                counter++;
                continue;
            }

            output = max(output, helper(nums, prev, k, numOperations, counter));
            output = max(output, helper(nums, prev+k, k, numOperations-1, 1));

            counter = 1;
            prev = nums[i];
        }
        output = max(output, helper(nums, prev, k, numOperations, counter));
        output = max(output, helper(nums, prev+k, k, numOperations-1, 1));          

        return output;
    }
};