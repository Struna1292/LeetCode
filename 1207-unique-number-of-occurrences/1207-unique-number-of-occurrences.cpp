class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> nums(2000, 0);

        for (int i = 0; i < arr.size(); i++)
        {
            nums[arr[i]+1000]++;
        }

        sort(begin(nums), end(nums));

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                if (nums[i] == nums[i-1])
                {
                    return false;
                }
            }
        }

        return true;
    }
};