class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int output = -1;

        int currMin = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (output < nums[i] - currMin && nums[i] - currMin != 0) {
                output = nums[i] - currMin;
            }
            if (nums[i] < currMin) {
                currMin = nums[i];
            }   
        }

        return output;
    }
};