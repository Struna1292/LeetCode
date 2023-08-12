class Solution {
public:
    bool isPalindrome(string& s, int ignore)
    {
        int i = 0;
        int j = s.length()-1;
        while (i < j)
        {
            if (i == ignore)
            {
                i++;
            }
            else if (j == ignore)
            {
                j--;
            }
            if (i == j)
                break;

            if (s[i] != s[j])
            {
                return false;
            }
            else
            {
                i++;
                j--;
            }
        }

        return true;
    }

    bool validPalindrome(string s) {
        int i = 0;
        int j = s.length()-1;

        while (i < j)
        {
            if (s[i] == s[j])
            {
                i++;
                j--;
            }
            else
            {
                if (isPalindrome(s, i) || isPalindrome(s, j))
                    return true;
                else
                    return false;
            }
        }

        return true;
    }
};