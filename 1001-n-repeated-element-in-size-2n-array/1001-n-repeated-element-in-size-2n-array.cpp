class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        map<int,int> mp;

        for (int n : nums)
        {
            mp[n]++;
        }   

        int output = 0;
        for (auto itr = mp.begin(); itr != mp.end(); itr++)
        {
            if (itr->second > 1)
            {
                output = itr->first;
            }
        }

        return output;
    }
};