class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        
        vector<bool> alph(26, true);

        for (int i = 0; i < brokenLetters.length(); i++) {
            alph[brokenLetters[i]-'a'] = false;
        }

        int wordsCounter = 0;
        bool possibleWord = true;

        for (int i = 0; i < text.length(); i++) {
            if (text[i] == ' ') {
                if (possibleWord) {
                    wordsCounter++;
                }

                possibleWord = true;
            }
            else if (!alph[text[i]-'a']) {
                possibleWord = false;
            }
        }
        if (possibleWord) {
            wordsCounter++;
        }        

        return wordsCounter;
    }
};