class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        
        unordered_set<int> us;

        int currSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            us.insert(nums[i]);
            currSum += nums[i];
        }

        int output = (currSum / (signed)nums.size()) + 1;

        if (output <= 0) {
            output = 1;
        }

        while (us.contains(output)) {
            output++;
        }

        return output;
    }
};