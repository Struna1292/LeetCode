class Solution {
public:
    string makeSmallestPalindrome(string s) {

        int i = 0;
        int j = s.length()-1;
        while (i < j)
        {
            if (s[i] > s[j])
            {
                s[i] = s[j];
            }
            else if (s[i] < s[j])
            {
                s[j] = s[i];
            }
            i++;
            j--;
        }

        return s;
    }   
};