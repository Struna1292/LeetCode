class Solution {
public:
    int specialArray(vector<int>& nums) {

        if (nums.size() == 1 && nums[0] == 1)
        {
            return 1;
        }
        
        sort(begin(nums), end(nums));

        for (int i = 1; i <= nums[nums.size()-1]; i++)
        {
            int index = lower_bound(begin(nums), end(nums), i) - begin(nums);

            if (i == (nums.size()-index))
            {
                return i;
            }
        }

        return -1;
    }
};