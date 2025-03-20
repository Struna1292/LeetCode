class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        
        if (k == nums.size())
        {
            int biggest = nums[0];
            for (int i = 1; i < nums.size(); i++)
            {
                if (biggest < nums[i])
                {
                    biggest = nums[i];
                }
            }
            return biggest;
        }
        else if (k == 1)
        {
            map<int, int> mp;

            for (int n : nums)
            {
                mp[n]++;
            }

            int biggest = -1;

            for (auto itr = mp.begin(); itr != mp.end(); itr++)
            {
                if (itr->second == 1 && itr->first > biggest)
                {
                    biggest = itr->first;
                }
            }

            return biggest;
        }

        map<int, int> mp;

        for (int n : nums)
        {
            mp[n]++;
        }

        if (mp[nums[0]] > 1 && mp[nums[nums.size()-1]] > 1)
        {
            return -1;
        }

        if (mp[nums[0]] == 1 && mp[nums[nums.size()-1]] == 1)
        {   
            return nums[0] > nums[nums.size()-1] ? nums[0] : nums[nums.size()-1];
        }   

        if (mp[nums[nums.size()-1]] == 1)
        {   
            return nums[nums.size()-1];
        }

        return nums[0];   
    }
};