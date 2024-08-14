class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, vector<int>> mp;

        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]].push_back(i);
        }

        map<int, vector<int>>::iterator itr;

        for (itr = mp.begin(); itr != mp.end(); itr++)
        {
            for (int j = itr->second.size()-2; j >= 0; j--)
            {
                if (itr->second[j+1] - itr->second[j] <= k)
                {
                    return true;
                }
            }
        }

        return false;
    }
};