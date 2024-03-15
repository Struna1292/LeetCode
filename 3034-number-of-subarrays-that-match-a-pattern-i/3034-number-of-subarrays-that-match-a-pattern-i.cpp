class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int output = 0;

        for (int i = 0; i < nums.size() - pattern.size(); i++)
        {
            bool match = true;
            int k = 0;
            for (int j = i+1; j < i + pattern.size() + 1; j++)
            {
                if (pattern[k] == -1)
                {
                    if (nums[j-1] <= nums[j])
                    {
                        match = false;
                        break;
                    }
                }
                else if (pattern[k] == 0)
                {
                    if (nums[j-1] != nums[j])
                    {
                        match = false;
                        break;
                    }
                }
                else
                {
                    if (nums[j-1] >= nums[j])
                    {
                        match = false;
                        break;
                    }
                }
                k++;
            }
            if (match)
            {
                output++;
            }
        }

        return output;
    }
};