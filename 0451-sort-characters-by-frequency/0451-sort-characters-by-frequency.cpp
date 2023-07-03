class Solution {
public:
    string frequencySort(string s) {

        vector<pair<int,char>> freq;

        for (int i = 0; i < s.length(); i++)
        {
            int counter = 0;
            for (int j = 0; j < freq.size(); j++)
            {
                if (s[i] == freq[j].second)
                {
                    freq[j].first++;
                    counter = 0;
                    break;
                }
                else
                {
                    counter++;
                }
            }

            if (counter == freq.size())
            {
                freq.push_back({1, s[i]});
            }
        }

        sort(begin(freq), end(freq));

        int k = 0;
        for (int i = freq.size()-1; i >= 0; i--)
        {
            for (int j = 0; j < freq[i].first; j++)
            {
                s[k] = freq[i].second;
                k++;
            }
        }

        return s;
    }
};