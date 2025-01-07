class Solution {
public:
    bool contains(string s, string sub)
    {
        if (s.length() <= sub.length())
        {
            return false;
        }

        for (int i = 0; i < s.length()-sub.length()+1; i++)
        {
            bool match = true;
            for (int j = 0; j < sub.length(); j++)
            {
                if (s[i+j] != sub[j])
                {
                    match = false;
                    break;
                }
            }

            if (match)
            {
                return true;
            }
        }

        return false;
    }

    vector<string> stringMatching(vector<string>& words) {

        vector<string> output;

        for (int i = 0; i < words.size(); i++)
        {
            for (int j = 0; j < words.size(); j++)
            {
                if (contains(words[j], words[i]))
                {
                    output.push_back(words[i]);
                    break;
                }
            }
        }

        return output;
    }
};