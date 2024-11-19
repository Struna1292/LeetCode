class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        
        if (k == 1)
        {
            int biggest = nums[0];
            for (int i = 1; i < nums.size(); i++)
            {
                if (nums[i] > biggest)
                {
                    biggest = nums[i];
                }
            }
            return biggest;
        }

        map<int,int> mp;
        mp[nums[0]]++;

        long long curr = nums[0];
        long long output = 0;

        int j = 0;

        for (int i = 1; i < nums.size(); i++)
        {
            if (i - j == k)
            {
                curr -= nums[j];
                mp[nums[j]]--;

                if (mp[nums[j]] == 0)
                {
                    mp.erase(nums[j]);
                }
                j++;
            }
            curr += nums[i];
            mp[nums[i]]++;

            if (mp[nums[i]] > 1)
            {
                while (true)
                {
                    curr -= nums[j];
                    mp[nums[j]]--;
                    
                    if (mp[nums[j]] == 0)
                    {
                        mp.erase(nums[j]);
                    }

                    if (nums[j] == nums[i])
                    {
                        j++;
                        break;
                    }
                    j++;
                }
            }

            if (i - j + 1 == k && curr > output)
            {
                output = curr;
            }
        }

        return output;
    }
};