class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {
        
        int alph[26] = { 0 };

        int counter = 0;

        for (int i = 0; i < s.length(); i++)
        {   
            alph[s[i]-'a']++;
            counter++;

            if (counter == k)
            {
                if (alph[s[i]-'a'] == k)
                {   
                    if ((i-k < 0 || s[i-k] != s[i]) && (i+1 == s.length() || s[i+1] != s[i]))
                    {
                        return true;
                    }
                    else
                    {
                        alph[s[i-counter+1]-'a']--;
                        counter--;
                    }
                }
                else
                {
                    int j = i-counter+1;
                    while (alph[s[j]-'a'] != counter)
                    {
                        alph[s[j]-'a']--;
                        counter--;
                        j++;
                    }
                }
            }
        }

        return false;
    }
};