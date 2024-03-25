class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        sort(begin(nums), end(nums));

        vector<int> output;

        int prev = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == prev)
            {
                if (output.size() == 0 || output[output.size()-1] != nums[i])
                {
                    output.push_back(nums[i]);
                }
            }
            prev = nums[i];
        }

        return output;
    }
};