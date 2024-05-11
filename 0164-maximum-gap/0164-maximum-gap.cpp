class Solution {
public:
    int maximumGap(vector<int>& nums) {
        
        sort(begin(nums), end(nums));

        int diff = 0;
        int prev = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            if ((nums[i] - prev) > diff)
            {
                diff = nums[i] - prev;
            }
            prev = nums[i];
        }

        return diff;
    }
};