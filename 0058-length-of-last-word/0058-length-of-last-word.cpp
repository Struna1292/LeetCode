class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int i = s.length()-1;

        while (s[i] == ' ')
        {
            i--;
        }

        int length = 0;

        while (i >= 0 && s[i] != ' ')
        {
            i--;
            length++;
        }

        return length;
    }
};