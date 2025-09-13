class Solution {
public:
    bool isVowel(char c) {
        string vowels = "aeiou";

        for (int i = 0; i < vowels.length(); i++) {
            if (vowels[i] == c) {
                return true;
            }
        }

        return false;
    }

    int maxFreqSum(string s) {
        
        int alph[26] = { 0 };

        for (int i = 0; i < s.length(); i++) {
            alph[s[i]-'a']++;
        }

        int bestVowel = 0;
        int bestConsonant = 0;

        for (int i = 0; i < 26; i++) {
            if (isVowel(i+'a')) {
                bestVowel = max(alph[i], bestVowel);
            }
            else {
                bestConsonant = max(alph[i], bestConsonant);
            }
        }

        return bestVowel + bestConsonant;
    }
};