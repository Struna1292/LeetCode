class Solution {
public:
    bool areOccurrencesEqual(string s) {
        vector<pair<char,int>> occurrences;
        int counter = 0;
        for (int i = 0; i < s.length(); i++)
        {
            counter = 0;
            for (int j = 0; j < occurrences.size(); j++)
            {
                if (s[i] != occurrences[j].first)
                {
                    counter++;
                }
                else
                {
                    occurrences[j].second++;
                    break;
                }
            }
            if (counter == occurrences.size())
            {
                occurrences.push_back({s[i], 1});
            }
        }

        int check = occurrences[0].second;
        for (int i = 0; i < occurrences.size(); i++)
        {
            if (occurrences[i].second != check)
            {
                return false;
            }
        }
        return true;
    }
};