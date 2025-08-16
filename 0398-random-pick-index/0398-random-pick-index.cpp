class Solution {
public:
    unordered_map<int, vector<int>> um; // value 

    Solution(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            um[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        int randomIndex = rand() % um[target].size();
        return um[target][randomIndex];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */