class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        
        map<string, int> words;

        string curr;

        for (int i = 0; i < s1.length(); i++)
        {
            if (s1[i] == ' ')
            {
                words[curr]++;
                curr = "";
            }
            else
            {
                curr.push_back(s1[i]);
            }
        }
        words[curr]++;

        curr = "";

        for (int i = 0; i < s2.length(); i++)
        {
            if (s2[i] == ' ')
            {
                words[curr]++;
                curr = "";
            }
            else
            {
                curr.push_back(s2[i]);
            }
        }
        words[curr]++;

        vector<string> output;

        for (auto itr = words.begin(); itr != words.end(); itr++)
        {
            if (itr->second == 1)
            {
                output.push_back(itr->first);
            }
        }

        return output;
    }
};