class Solution {
public:
    bool isVowel(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            return true;
        }
        return false;
    }

    bool isDigit(char c) {
        if (c >= '0' && c <= '9') {
            return true;
        }
        return false;
    }

    int vowelConsonantScore(string s) {
        int vowels = 0;
        int consonants = 0;

        for (int i = 0; i < s.length(); i++) {
            if (isVowel(s[i])) {
                vowels++;
            }
            else if (!isDigit(s[i]) && s[i] != ' ') {
                consonants++;
            }
        }

        if (consonants == 0) {
            return 0;
        }

        return floor(vowels/consonants);
    }
};