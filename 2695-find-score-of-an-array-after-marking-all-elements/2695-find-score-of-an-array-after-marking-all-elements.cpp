class Solution {
public:
    void removeKeyValue(int key, int value, multimap<int, int>& mp)
    {
        for (auto itr = mp.find(key); itr != mp.end(); itr++)
        {
            if (itr->first != key || (itr->first == key && itr->second > value))
            {
                return;
            }
            if (itr->first == key && itr->second == value)
            {
                mp.erase(itr);
                return;
            }
        }
    }

    long long findScore(vector<int>& nums) {
        
        multimap<int, int> mp;

        for (int i = 0; i < nums.size(); i++)
        {
            mp.insert({nums[i], i});
        }

        long long output = 0;

        for (auto itr = mp.begin(); itr != mp.end(); itr++)
        {
            output += itr->first;

            int indexLeft = itr->second-1;
            if (indexLeft != -1)
            {
                int value = nums[indexLeft];
                removeKeyValue(value, indexLeft, mp);
            }


            int indexRight = itr->second+1;
            if (indexRight < nums.size())
            {
                int value = nums[indexRight];
                removeKeyValue(value, indexRight, mp);
            }


            mp.erase(itr);
        }

        return output;
    }
};