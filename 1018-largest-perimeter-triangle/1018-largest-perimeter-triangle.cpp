class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        
        sort(begin(nums), end(nums));

        for (int i = nums.size()-2; i >= 1; i--) {
            if (nums[i-1] + nums[i] > nums[i+1]) {
                return nums[i-1] + nums[i] + nums[i+1];
            }
        }

        return 0;
    }
};