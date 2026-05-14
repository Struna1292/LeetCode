class Solution {
public:
    bool isGood(vector<int>& nums) {
        unordered_map<int, int> um;

        for (int i = 0; i < nums.size(); i++) {
            um[nums[i]]++;
        }

        int n = nums.size()-1;
        for (int i = 1; i < n; i++) {
            if (um[i] != 1) {
                return false;
            }
        }

        if (um[n] != 2) {
            return false;
        }

        return true;
    }   
};