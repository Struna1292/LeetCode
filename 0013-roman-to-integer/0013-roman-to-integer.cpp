class Solution {
public:
    int romanToInt(string s) {
        vector<pair<int,char>> symbols = { {1,'I'}, {5, 'V'}, {10, 'X'}, {50, 'L'}, {100, 'C'}, {500, 'D'}, {1000, 'M'}};
        int output = 0;
        int prev = 0;
        for (int i = 0; i < s.length(); i++)
        {
            for (int j = 0; j < symbols.size(); j++)
            {
                if (s[i] == symbols[j].second)
                {
                    if (symbols[j].first > prev)
                    {
                        output += symbols[j].first - prev - prev;
                    }
                    else
                    {
                        output += symbols[j].first;

                    }
                    prev = symbols[j].first;
                    break;
                }
            }
        }
        return output;
    }
};