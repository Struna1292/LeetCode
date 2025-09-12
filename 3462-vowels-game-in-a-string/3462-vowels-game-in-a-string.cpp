class Solution {
public:
    bool isVowel(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            return true;
        }
        return false;
    }

    bool doesAliceWin(string s) {
        
        int counter = 0;

        for (char &c : s) {
            if (isVowel(c)) {
                counter++;
            }
        }
        // alice loses only when there is no vowels

        return counter > 0;
    }
};