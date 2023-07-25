class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        sort(begin(nums), end(nums));

        vector<int> output;
        for (int i = 0; i < nums.size()-1; i++)
        {
            if (nums[i] == nums[i+1])
            {
                output.push_back(nums[i]);
                i++;
            }
        }

        return output;
    }
};