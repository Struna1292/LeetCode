class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        vector<int> output = nums;
        for (int i = nums.size()-1; i >= 0; i--) {
            output.push_back(nums[i]);
        }

        return output;
    }
};