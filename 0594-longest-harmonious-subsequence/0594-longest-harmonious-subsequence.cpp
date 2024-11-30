class Solution {
public:
    int findLHS(vector<int>& nums) {
        
        map<int,int> mp;

        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }

        auto prev = mp.begin();
        int output = 0;
        for (auto itr = mp.begin(); itr != mp.end(); itr++)
        {
            if (itr != prev)
            {
                if (prev->first+1 == itr->first && prev->second+itr->second > output)
                {
                    output = prev->second+itr->second;
                }
            }
            prev = itr;
        }

        return output;
    }
};