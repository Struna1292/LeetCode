class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
        {
            return false;
        }

        vector<int> sAlph(26, 0);
        vector<int> tAlph(26, 0);

        for (int i = 0; i < s.length(); i++)
        {
            sAlph[s[i]-'a']++;
            tAlph[t[i]-'a']++;
        }

        for (int i = 0; i < 26; i++)
        {
            if (sAlph[i] != tAlph[i])
            {
                return false;
            }
        }
        
        return true;
    }
};