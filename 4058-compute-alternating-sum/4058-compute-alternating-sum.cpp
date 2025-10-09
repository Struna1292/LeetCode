class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int output = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0) {
                output += nums[i];
            }
            else {
                output -= nums[i];
            }
        }

        return output;
    }
};