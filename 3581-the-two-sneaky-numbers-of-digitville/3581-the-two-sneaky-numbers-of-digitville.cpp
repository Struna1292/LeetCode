class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        
        vector<int> occs(nums.size(), 0);
        vector<int> output;

        for (int i = 0; i < nums.size(); i++) {
            occs[nums[i]]++;
            if (occs[nums[i]] > 1) {
                output.push_back(nums[i]);
            }
        }

        return output;
    }
};