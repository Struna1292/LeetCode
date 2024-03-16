class Solution {
public:
    int removePalindromeSub(string s) {
        
        bool onlyA = true;
        bool onlyB = true;

        int i = 0;
        int j = s.length()-1;

        bool palindrome = true;

        while (i < j)
        {
            if (s[i] != s[j])
            {
                palindrome = false;
            }

            if (s[i] == 'a')
            {
                onlyB = false;
            }
            else
            {
                onlyA = false;
            }

            if (s[j] == 'a')
            {
                onlyB = false;
            }
            else
            {
                onlyA = false;
            }

            i++;
            j--;
        }

        if (palindrome)
        {
            return true;
        }


        if (onlyA || onlyB)
        {
            return 1;
        }
        
        return 2;
    }
};