class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        
        map<int,vector<int>> mp;

        for (int i = 0; i < cards.size(); i++)
        {
            mp[cards[i]].push_back(i);
        }

        map<int,vector<int>>::iterator itr;

        int output = -1;

        for (itr = mp.begin(); itr != mp.end(); itr++)
        {
            for (int i = 1; i < itr->second.size(); i++)
            {
                if (output == -1 || output > (itr->second[i] - itr->second[i-1] + 1))
                {
                    output = itr->second[i] - itr->second[i-1] + 1;
                }
            }
        }

        return output;
    }
};