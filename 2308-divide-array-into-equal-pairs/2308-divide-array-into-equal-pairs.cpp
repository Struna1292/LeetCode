class Solution {
public:
    bool divideArray(vector<int>& nums) {
        
        map<int, int> mp;

        for (int n : nums)
        {
            mp[n]++;
        }

        for (auto itr = mp.begin(); itr != mp.end(); itr++)
        {
            if (itr->second % 2 != 0)
            {
                return false;
            }
        }

        return true;
    }
};