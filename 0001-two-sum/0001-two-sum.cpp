class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int, int> um;

        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];

            if (um.find(diff) != um.end()) {
                return {um[diff], i};
            }

            um[nums[i]] = i;
        }

        return {};
    }
};