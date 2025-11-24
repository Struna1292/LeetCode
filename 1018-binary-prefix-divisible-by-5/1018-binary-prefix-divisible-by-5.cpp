class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        
        int curr = 0;
        vector<bool> output(nums.size(), false);

        for (int i = 0; i < nums.size(); i++) {
            curr <<= 1;
            if (nums[i] == 1) {
                curr |= 1;
            }

            if (curr % 5 == 0) {
                output[i] = true;
            }
            curr %= 10;
        }

        return output;
    }
};