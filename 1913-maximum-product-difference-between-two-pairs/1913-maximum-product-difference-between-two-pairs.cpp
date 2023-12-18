class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(begin(nums), end(nums));
        return nums[nums.size()-1] * nums[nums.size()-2] - nums[0] * nums[1];
    }
};