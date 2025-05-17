class Solution {
public:
    int minDeletion(string s, int k) {
        
        map<char, int> mp;

        for (char c : s)
        {
            mp[c]++;
        }

        vector<int> nums;

        for (auto itr = mp.begin(); itr != mp.end(); itr++)
        {
            nums.push_back(itr->second);
        }

        sort(begin(nums), end(nums));

        int counter = 0;
        int limit = mp.size() - k;
        
        for (int i = 0; i < limit; i++)
        {
            counter += nums[i];
        }

        return counter;
    }
};