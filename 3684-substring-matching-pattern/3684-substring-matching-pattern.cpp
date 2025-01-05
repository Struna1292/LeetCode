class Solution {
public:
    int findSubstring(string s, int startIndex, string find)
    {
        for (int i = startIndex; i < s.length()-find.length()+1; i++)
        {
            int j = i;

            bool match = true;

            for (int k = 0; k < find.length(); k++)
            {
                if (find[k] != s[j])
                {
                    match = false;
                    break;
                }
                j++;
            }   

            if (match)
            {
                return j;
            }
        }

        return -1;
    }

    bool hasMatch(string s, string p) {
        
        string prefix;
        string suffix;

        bool star = false;

        for (int i = 0; i < p.length(); i++)
        {
            if (p[i] == '*')
            {
                star = true;
            }
            else if (star)
            {
                suffix.push_back(p[i]);
            }
            else
            {
                prefix.push_back(p[i]);
            }
        }

        if (prefix.length() == 0 && suffix.length() == 0)
        {
            return true;
        }

        if (prefix.length() > 0)
        {   
            int i = findSubstring(s, 0, prefix);
            
            if (i == -1)
            {
                return false;
            }

            if (suffix.length() == 0)
            {
                return true;
            }

            if (findSubstring(s, i, suffix) != -1)
            {
                return true;
            }
        }
        else
        {
            if (findSubstring(s, 0, suffix) != -1)
            {
                return true;
            }
        }


        return false;
    }
};