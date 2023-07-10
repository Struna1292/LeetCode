class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        
        sort(begin(nums), end(nums));

        vector<int> output;

        for (int i = 0; i < nums.size(); i++)
        {
            bool lonely = true;
            if (i-1 >= 0)
            {
                if (nums[i-1]+1 == nums[i] || nums[i-1] == nums[i])
                {
                    lonely = false;
                }
            }

            if (i+1 < nums.size())
            {
                if (nums[i+1]-1 == nums[i] || nums[i+1] == nums[i])
                {
                    lonely = false;
                }
            }

            if (lonely)
            {
                output.push_back(nums[i]);
            }
        }

        return output;
    }
};