class Solution {
public:
    int minAnagramLength(string s) {
        
        for (int length = 1; length < s.length(); length++)
        {
            if (s.length() % length == 0)
            {

                int alph[26] = { 0 };

                for (int i = 0; i < length; i++)
                {
                    alph[s[i]-'a']++;
                }

                bool matching = true;

                for (int i = length; i < s.length(); i += length)
                {
                    int curr[26] = { 0 };

                    for (int j = i; j < i+length; j++)
                    {
                        curr[s[j]-'a']++;
                    }

                    for (int j = 0; j < 26; j++)
                    {
                        if (alph[j] != curr[j])
                        {
                            matching = false;
                            break;
                        }
                    }

                    if (!matching)
                    {
                        break;
                    }
                }

                if (matching)
                {
                    return length;
                }

            }
        }

        return s.length();
    }
};