class Solution {
public:
    char findTheDifference(string s, string t) {
        s += t;
        sort(begin(s), end(s));

        char prev = s[0];
        int counter = 1;
        for (int i = 1; i < s.length(); i++)
        {
            if (s[i] == prev)
            {
                counter++;
            }
            else
            {
                if (counter % 2 != 0)
                {
                    return prev;
                }
                counter = 1;
                prev = s[i];
            }
            if (i+1 == s.length())
            {
                return prev;
            }
        }
        
        return prev;

    }
};