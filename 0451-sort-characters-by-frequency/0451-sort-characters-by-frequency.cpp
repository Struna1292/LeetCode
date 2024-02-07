class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int,char>> freq;

        for (int i = 0; i < s.length(); i++)
        {
            bool found = false;
            for (int j = 0; j < freq.size(); j++)
            {
                if (freq[j].second == s[i])
                {
                    freq[j].first++;
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                freq.push_back({1,s[i]});
            }
        }

        sort(begin(freq), end(freq));

        string output;

        for (int i = freq.size()-1; i >= 0; i--)
        {
            for (int j = 0; j < freq[i].first; j++)
            {
                output.push_back(freq[i].second);
            }
        }

        return output;
    }
};