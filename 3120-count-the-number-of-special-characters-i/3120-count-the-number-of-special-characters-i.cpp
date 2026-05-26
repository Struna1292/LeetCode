class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> us;

        for (int i = 0; i < word.length(); i++) {
            us.insert(word[i]);
        }

        int output = 0;
        for (int i = 0; i < 26; i++) {
            char lowerCase = 'a' + i;
            char upperCase = 'A' + i;

            if (us.contains(lowerCase) && us.contains(upperCase)) {
                output++;
            }
        }

        return output;
    }
};