class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(begin(nums), end(nums));

        int counter = 1;
        int prev = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != prev)
            {
                if (counter == 1)
                {
                    return prev;
                }
                prev = nums[i];
                counter = 1;
            }
            else
            {
                counter++;
            }
        }

        return nums[nums.size()-1];
    }
};