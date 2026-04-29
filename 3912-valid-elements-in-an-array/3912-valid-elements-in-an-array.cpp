class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        if (nums.size() <= 2) {
            return nums;
        }

        int currMax = nums[nums.size()-1];
        vector<int> maxs(nums.size(), currMax);
        for (int i = nums.size()-1; i >= 0; i--) {
            currMax = max(currMax, nums[i]);
            maxs[i] = currMax;
        }

        vector<int> output;
        output.push_back(nums[0]);
        currMax = nums[0];

        for (int i = 1; i < nums.size()-1; i++) {
            if (nums[i] > currMax || nums[i] > maxs[i+1]) {
                output.push_back(nums[i]);
            }

            currMax = max(currMax, nums[i]);
        }

        output.push_back(nums[nums.size()-1]);

        return output;
    }
};