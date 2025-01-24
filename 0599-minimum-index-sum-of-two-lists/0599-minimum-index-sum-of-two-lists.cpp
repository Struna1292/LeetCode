class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        
        map<string,int> mp;

        int prev = -1;

        for (int i = 0; i < list2.size(); i++)
        {
            mp[list2[i]] = i+1;
        }

        vector<string> output;

        for (int i = 0; i < list1.size(); i++)
        {
            if (mp[list1[i]] != 0)
            {
                if (prev == mp[list1[i]] + i || prev == -1)
                {
                    prev = mp[list1[i]] + i;
                    output.push_back(list1[i]);
                }
                else if (prev > mp[list1[i]] + i)
                {
                    output = {};
                    prev = mp[list1[i]] + i;
                    output.push_back(list1[i]);
                }

            }
        }

        return output;
    }
};