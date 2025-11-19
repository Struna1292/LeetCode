class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int> us;

        for (int i = 0; i < nums.size(); i++) {
            us.insert(nums[i]);
        }

        while (us.contains(original)) {
            original += original;
        }

        return original;
    }
};