class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int output = 0;

        for (string& word : words) {
            for (int i = 0; i < word.length(); i++) {
                if (word[i] != s[i]) {
                    break;
                }

                if (i+1 == word.length()) {
                    output++;
                }
            }
        }

        return output;
    }
};