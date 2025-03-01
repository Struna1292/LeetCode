class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        
        vector<int> output(nums.size(), 0);

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i-1] == nums[i])
            {
                nums[i-1] *= 2;
                nums[i] = 0;
            }
        }

        int j = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                output[j] = nums[i];
                j++;
            }
        }

        return output;
    }
};