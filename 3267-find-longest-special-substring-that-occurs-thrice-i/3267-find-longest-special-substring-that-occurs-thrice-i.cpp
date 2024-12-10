class Solution {
public:
    int maximumLength(string s) {
        
        map<string, int> mp;

        int counter = 1;
        int prev = s[0];

        for (int i = 1; i < s.length(); i++)
        {
            if (s[i] == prev)
            {
                counter++;
            }
            else
            {
                string curr;
                
                int times = counter;

                while (times > 0)
                {
                    curr.push_back(prev);
                    mp[curr] += times;
                    times--;
                }

                counter = 1;
                prev = s[i];
            }
        }

        string curr;     
        int times = counter;

        while (times > 0)
        {
            curr.push_back(prev);
            mp[curr] += times;
            times--;
        }

        int output = -1;

        for (auto itr = mp.begin(); itr != mp.end(); itr++)
        {
            int currLength = itr->first.length();
            if (itr->second >= 3 && currLength > output)
            {
                output = itr->first.length();
            }
        }

        return output;
    }
};