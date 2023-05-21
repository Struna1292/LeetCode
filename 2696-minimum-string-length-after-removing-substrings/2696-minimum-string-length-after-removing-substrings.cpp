class Solution {
public:
    int minLength(string s) {

        stack<char> letters;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'B' || s[i] == 'D')
            {
                if (!letters.empty() && (letters.top() == 'A' && s[i] == 'B' || letters.top() == 'C' && s[i] == 'D'))
                {
                    letters.pop();
                }
                else
                {
                    letters.push(s[i]);
                }
            }
            else
            {
                letters.push(s[i]);
            }
        }

        return letters.size();
    }
};