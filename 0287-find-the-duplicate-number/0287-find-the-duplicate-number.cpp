class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(begin(nums), end(nums));

        for (int i = 0; i < nums.size()-1; i++)
        {
            if (nums[i] == nums[i+1])
            {
                return nums[i];
            }
        }

        return -1;
    }
};