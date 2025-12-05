class Solution {
public:
    string smallestPalindrome(string s) {
        
        int alph[26] = { 0 };

        for (int i = 0; i < s.length(); i++) {
            alph[s[i]-'a']++;
        }

        int k = 0;
        int l = s.length()-1;
        for (int i = 0; i < 26; i++) {
            while (alph[i] > 1) {
                char curr = 'a' + i;

                s[k] = curr;
                s[l] = curr;

                k++;
                l--;
                alph[i] -= 2;
            }
        }

        return s;
    }
};