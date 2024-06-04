class Solution {
public:
    int longestPalindrome(string s) {
        
        int alph[52] = { 0 };

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] >= 'a' && s[i] <= 'z')
            {
                alph[s[i]-'a']++;
            }
            else
            {
                alph[s[i]-'A'+26]++;
            }
        }

        int output = 0;

        for (int i = 0; i < 52; i++)
        {
            if (alph[i] > 0)
            {
                if (alph[i] % 2 == 0 || output == 0 || output % 2 == 0)
                {
                    output += alph[i];
                }
                else
                {
                    output += alph[i]-1;
                }
            }   
        }

        return output;
    }
};