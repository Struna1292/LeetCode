class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int currMin = nums[nums.size()-1];
        vector<int> mins(nums.size(), currMin);

        for (int i = nums.size()-1; i >= 0; i--) {
            currMin = min(currMin, nums[i]);
            mins[i] = currMin;
        }


        int currMax = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            currMax = max(currMax, nums[i]);

            if (currMax - mins[i] <= k) {
                return i;
            } 
        }

        return -1;
    }
};