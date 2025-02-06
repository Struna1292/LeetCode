class Solution {
public:
    int helper(int n)
    {
        int output = 0;
        for (int i = 1; i <= n; i++)
        {
            output += i;
        }
        return output;
    }

    int tupleSameProduct(vector<int>& nums) {
        
        map<int, vector<vector<int>>> mp;

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i+1; j < nums.size(); j++)
            {
                mp[nums[i]*nums[j]].push_back({nums[i], nums[j]});
            }
        }

        int output = 0;

        for (auto itr = mp.begin(); itr != mp.end(); itr++)
        {
            if (itr->second.size() > 1)
            {
                // every tuple can be swap places into 8 different combinations
                // now the total combinations is with every pair one less because its already used for example (5 + 4 + 3 + 2 + 1) * 8
                output += helper(itr->second.size()-1) * 8;
            }
        }

        return output;
    }
};