class Solution {
public:
    int minMoves(vector<int>& nums) {
        
        int sum = nums[0];
        int maxNum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            maxNum = max(maxNum, nums[i]);
            sum += nums[i];
        }

        return (maxNum * nums.size()) - sum;
    }
};