class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string curr;
        string empty;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ' ')
            {
                if (curr.length() != 0)
                {
                    words.push_back(curr);
                }
                curr = empty;
            }
            else
            {
                curr.push_back(s[i]);
            }
            if (i+1 == s.length())
            {
                if (curr.length() != 0)
                {
                    words.push_back(curr);
                }
            }
        }

        string output;
        for (int i = words.size()-1; i >= 0; i--)
        {
            for (int j = 0; j < words[i].size(); j++)
            {
                output.push_back(words[i][j]);
            }
            if (i != 0)
            {
                output.push_back(' ');
            }
        }

        return output;
    }
};