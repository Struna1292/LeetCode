class Solution {
public:
    int numRabbits(vector<int>& answers) {
        map<int, int> mp;
        int output = 0;
        for (int n : answers)
        {
            if (n == 0)
            {
                output++;
            }
            else
            {
                mp[n]++;
            }
        }

        for (auto itr = mp.begin(); itr != mp.end(); itr++)
        {
            output += (itr->second / (itr->first+1)) * (itr->first+1);
            if (itr->second % (itr->first+1) != 0)
            {
                output += itr->first+1;
            }
        }

        return output;
    }
};