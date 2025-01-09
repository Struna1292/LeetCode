class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        
        int output = 0;
        
        for (string s : words)
        {
            if (s.length() < pref.length())
            {
                continue;
            }

            bool match = true;
            for (int i = 0; i < pref.length(); i++)
            {
                if (pref[i] != s[i])
                {
                    match = false;
                }
            }

            if (match)
            {
                output++;
            }
        }

        return output;
    }
};