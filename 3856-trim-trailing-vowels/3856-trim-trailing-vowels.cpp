class Solution {
public:
    bool isVowel(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            return true;
        }
        return false;
    }

    string trimTrailingVowels(string s) {
        string output;
        int i = s.length()-1;
        for (; i >= 0; i--) {
            if (!isVowel(s[i])) {
                break;
            }
        }

        for (int j = 0; j <= i; j++) {
            output.push_back(s[j]);
        }

        return output;
    }
};