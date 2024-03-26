class Solution {
public:
    int maximumLengthSubstring(string s) {

        int output = 0;
        
        for (int i = 0; i < s.length(); i++)
        {

            int curr[26] = { 0 };

            bool found = false;

            for (int j = i; j < s.length(); j++)
            {
                if (curr[s[j]-'a'] == 2)
                {
                    if (j-i > output)
                    {
                        output = j-i;
                    }
                    found = true;
                    break;
                }
                else
                {
                    curr[s[j]-'a']++;
                }
            }

            if (!found)
            {
                if (s.length()-i > output)
                {
                    output = s.length()-i;
                }
            }
        }
        
        return output;
    }
};