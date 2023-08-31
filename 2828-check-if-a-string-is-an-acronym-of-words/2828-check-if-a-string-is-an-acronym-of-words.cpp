class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        if (s.length() != words.size())
        {
            return false;
        }
        else
        {
            for (int i = 0; i < s.length(); i++)
            {
                if (s[i] != words[i][0])
                {
                    return false;
                }
            }
        }
        
        return true;
    }
};