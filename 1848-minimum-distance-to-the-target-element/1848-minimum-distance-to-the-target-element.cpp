class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int output = INT_MAX;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target && output > abs(i - start)) {
                output = abs(i - start);
            }
        }

        return output;
    }
};