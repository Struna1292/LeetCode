class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        
        map<int, int> mp;

        for (int n : nums)
        {
            mp[n]++;
        }

        int x = nums[0];
        int totalCounter = mp[x];

        for (auto itr = mp.begin(); itr != mp.end(); itr++)
        {
            if (totalCounter < itr->second)
            {
                totalCounter = itr->second;
                x = itr->first;
            }
        }

        int currCounter = 0;

        for (int i = 0; i < nums.size()-1; i++)
        {
            if (nums[i] == x)
            {
                currCounter++;
            }

            if (currCounter > (i+1)/2 && (totalCounter-currCounter) > (nums.size()-i-1)/2)
            {
                return i;
            }
        }


        return -1;
    }
};