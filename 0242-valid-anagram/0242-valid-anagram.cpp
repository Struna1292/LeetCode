class Solution {
public:
    bool isAnagram(string s, string t) {

        if (s.length() != t.length())
        {
            return false;
        }

        for (int i = 0; i < s.length(); i++)
        {
            if (t[i] != s[i])
            {
                int counter = i;
                for (int j = i; j < t.length(); j++)
                {
                    if (s[i] == t[j])
                    {
                        swap(t[i], t[j]);
                        break;
                    }
                    counter++;
                }
                if (counter == t.length())
                {
                    return false;
                }
            }
        }

        return true;
    }
};