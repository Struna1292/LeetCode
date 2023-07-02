class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        sort(begin(nums), end(nums), greater<int>());

        return nums[k-1];
    }
};