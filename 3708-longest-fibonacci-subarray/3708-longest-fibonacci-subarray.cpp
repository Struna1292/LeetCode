class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int counter = 0;
        int longest = 0;
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] == nums[i-1] + nums[i-2]) {
                counter++;
                longest = max(longest, counter);
            }
            else {
                counter = 0;
            }
        }
        
        return longest + 2;
    }
};