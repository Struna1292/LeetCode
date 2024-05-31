class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        map<int,int> mp;

        mp.insert({nums[0], 1});

        for (int i = 1; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }

        vector<int> output;

        map<int, int>::iterator itr;

        for (itr = mp.begin(); itr != mp.end(); ++itr) 
        {
            if (itr->second == 1)
            {
                output.push_back(itr->first);
            }
        }
        
        
        return output;
    }
};