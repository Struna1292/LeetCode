class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int, int> mp;

        int output = -1;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;

            if (mp[nums[i]] > mp[output]) {
                output = nums[i];
            }
        }

        return output;
    }
};