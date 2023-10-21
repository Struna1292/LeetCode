class Solution {
public:
    int findLUSlength(string a, string b) {

        if (a == b)
        {
            return -1;
        }

        if (a.length() > b.length())
        {
            return a.length();
        }
        return b.length();
    }
};