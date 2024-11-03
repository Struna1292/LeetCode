class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length())
        {
            return false;
        }

        int length = s.length();

        s += s;

        for (int i = 0; i < length; i++)
        {
            if (s[i] == goal[0])
            {
                bool match = true;

                for (int j = 1; j < goal.length(); j++)
                {
                    if (goal[j] != s[i+j])
                    {
                        match = false;
                        break;
                    }
                }

                if (match)
                {
                    return true;
                }
            }
        }

        return false;
    }
};