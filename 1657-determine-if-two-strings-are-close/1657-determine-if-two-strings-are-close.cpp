class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.length() != word2.length())
        {
            return false;
        }

        vector<int> a1(26, 0);
        vector<int> a2(26, 0);

        for (int i = 0; i < word1.length(); i++)
        {
            a1[word1[i]-'a']++;
            a2[word2[i]-'a']++;
        }

        vector<int> freq1;
        vector<int> freq2;

        for (int i = 0; i < 26; i++)
        {
            if (a1[i] == 0 && a2[i] > 0 || a1[i] > 0 && a2[i] == 0)
            {
                return false;
            }

            if (a1[i] > 0 && a2[i] > 0)
            {
                freq1.push_back(a1[i]);
                freq2.push_back(a2[i]);
            }
        }

        sort(begin(freq1), end(freq1));
        sort(begin(freq2), end(freq2));

        for (int i = 0; i < freq1.size(); i++)
        {
            if (freq1[i] != freq2[i])
            {
                return false;
            }
        }

        return true;
    }
};