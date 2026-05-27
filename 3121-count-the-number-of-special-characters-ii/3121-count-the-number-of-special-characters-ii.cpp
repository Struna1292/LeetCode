class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> us;
        unordered_set<char> failed;

        for (int i = 0; i < word.length(); i++) {
            if (word[i] >= 'a' && word[i] <= 'z') {
                char upperCase = 'A' + (word[i] - 'a');
                if (us.contains(upperCase)) {
                    failed.insert(word[i]);
                }
            }

            us.insert(word[i]);
        }

        int output = 0;
        for (int i = 0; i < 26; i++) {
            char lowerCase = 'a' + i;
            char upperCase = 'A' + i;

            if (!failed.contains(lowerCase) && us.contains(lowerCase) && us.contains(upperCase)) {
                output++;
            }
        }

        return output;
    }
};