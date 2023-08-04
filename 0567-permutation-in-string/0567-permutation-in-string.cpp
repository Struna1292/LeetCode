class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int alp[26] = { 0 };

        for (int i = 0; i < s1.length(); i++)
        {
            alp[s1[i]-'a']++;
        }

        int curr[26] = { 0 };
        int counter = 0;

        for (int i = 0; i < s2.length(); i++)
        {
            if (curr[s2[i]-'a'] < alp[s2[i]-'a'])
            {
                counter++;
                curr[s2[i]-'a']++;
                if (counter == s1.length())
                {
                    return true;
                }
            }
            else if (curr[s2[i]-'a'] == alp[s2[i]-'a'] && curr[s2[i]-'a'] != 0)
            {
                int j = i - counter;
                while (j < i)
                {
                    if (s2[j] == s2[i])
                        break;
                    curr[s2[j]-'a']--;
                    j++;
                    counter--;
                }

            }
            else
            {
                if (counter != 0)
                {
                    counter = 0;
                    for (int j = 0; j < 26; j++)
                        curr[j] = 0;
                }
            }
        }

        return false;
    }
};