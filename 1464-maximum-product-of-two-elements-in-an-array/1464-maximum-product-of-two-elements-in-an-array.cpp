class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(begin(nums), end(nums), greater<int>());

        return (nums[0]-1) * (nums[1]-1);
    }
};