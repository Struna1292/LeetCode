class Solution {
public:
    bool isVowel(char& c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            return true;
        }

        return false;
    }

    string reverseWords(string s) {
        int currVowels = 0;
        int startIndex = -1;
        
        bool firstWord = true;
        int firstVowels = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                if (firstWord) {
                    firstWord = false;
                    firstVowels = currVowels;
                }
                else if (currVowels == firstVowels) {
                    int j = startIndex + 1;
                    int k = i - 1;

                    while (j < k) {
                        swap(s[j], s[k]);
                        j++;
                        k--;
                    }
                }

                currVowels = 0;
                startIndex = i;
            }
            else {
                if (isVowel(s[i])) {
                    currVowels++;
                }
            }
        }
        if (currVowels == firstVowels) {
            int j = startIndex + 1;
            int k = s.length() - 1;

            while (j < k) {
                swap(s[j], s[k]);
                j++;
                k--;
            }
        }

        return s;
    }
};