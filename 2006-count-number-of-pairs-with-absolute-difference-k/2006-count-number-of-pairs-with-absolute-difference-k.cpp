class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        int counter = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i+1; j < nums.size(); j++)
            {
                if (abs(nums[i] - nums[j]) == k)
                {
                    counter++;
                }
                else if (abs(nums[i] - nums[j]) > k)
                {
                    break;
                }
            }
        }
        return counter;
    }
};