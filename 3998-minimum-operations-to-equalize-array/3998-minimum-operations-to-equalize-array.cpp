class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        unordered_map<int, int> um;

        for (int i = 0; i < nums.size(); i++) {
            um[nums[i]]++;
        }

        if (um.size() == 1) {
            return 0;
        }
        return 1;
    }
};