class Solution {
public:
    int helper(vector<int>& nums, int& val, int& k, int numOperations, int counter) {
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

        unordered_map<int, int> um;

        for (int i = 0; i < nums.size(); i++) {
            um[nums[i]]++;
        }

        sort(begin(nums), end(nums));
        int lowest = nums[0];
        int highest = nums[nums.size()-1];

        int output = 0;

        for (int i = lowest; i <= highest; i++) {
            if (um.contains(i)) {
                output = max(output, helper(nums, i, k, numOperations, um[i]));
            }
            else {
                output = max(output, helper(nums, i, k, numOperations-1, 1));
            }
        }    

        return output;
    }
};