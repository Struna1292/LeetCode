class Solution {
public:
    bool buddyStrings(string s, string goal) {

        if (s.length() != goal.length())
        {
            return false;
        }
        
        vector<int> diff;

        int alph[26] = { 0 };

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != goal[i])
            {
                diff.push_back(i);
            }
            alph[s[i]-'a']++;
        }


        if (diff.size() > 2 || diff.size() == 1)
        {
            return false;
        }
        else if (diff.size() == 2)
        {
            swap(s[diff[0]], s[diff[1]]);
            if (s == goal)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        for (int i = 0; i < 26; i++)
        {   
            if (alph[i] >= 2)
            {
                return true;
            }
        }

        return false;
    }   
};