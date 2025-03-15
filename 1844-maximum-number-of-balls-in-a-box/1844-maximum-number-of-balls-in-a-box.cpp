class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        
        map<int, int> mp;

        for (int i = lowLimit; i <= highLimit; i++)
        {
            string s = to_string(i);
            int curr = 0;
            for (char c : s)
            {
                curr += c - '0';
            }

            mp[curr]++;
        }

        int output = -1;

        for (auto itr = mp.begin(); itr != mp.end(); itr++)
        {
            if (output < itr->second)
            {
                output = itr->second;
            }
        }

        return output;
    }
};