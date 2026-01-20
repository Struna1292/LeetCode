class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& target) {
        unordered_map<int, int> um;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != target[i]) {
                um[nums[i]]++;
            }
        }

        return um.size();
    }
};