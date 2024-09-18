class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        
        map<int,int> mp;

        for (int num : nums)
        {
            mp[num]++;
        }

        vector<int> output;

        for (auto itr = mp.begin(); itr != mp.end(); itr++)
        {
            if (itr->second > 1)
            {
                output.push_back(itr->first);
            }
        }

        return output;
    }
};