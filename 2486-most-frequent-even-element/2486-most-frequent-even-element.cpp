class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int, int> mp;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] % 2 == 0)
            {
                mp[nums[i]]++;
            }
        }

        int freq = 0;
        int output = -1;

        for (auto itr = mp.begin(); itr != mp.end(); itr++)
        {
            if (itr->second > freq)
            {
                freq = itr->second;
                output = itr->first;
            }
        }

        return output;
    }
};