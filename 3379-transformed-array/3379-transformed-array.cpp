class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        vector<int> output(nums.size(), 0);

        for (int i = 0; i < nums.size(); i++) {
            int index = nums[i];
            if (nums[i] < 0) {
                index *= -1;
                index %= nums.size();
                index = nums.size() - index;
            }

            index = (i + index) % nums.size();
        
            output[i] = nums[index];
        }

        return output;
    }
};