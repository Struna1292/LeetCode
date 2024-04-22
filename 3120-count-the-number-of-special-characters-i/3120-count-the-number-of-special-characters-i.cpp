class Solution {
public:
    int numberOfSpecialChars(string word) {

        vector<int> lowerCase(26, 0);
        vector<int> upperCase(26, 0);


        for (int i = 0; i < word.length(); i++)
        {
            if (word[i] >= 65 && word[i] <= 90)
            {
                upperCase[word[i]-'A']++;
            }
            else
            {
                lowerCase[word[i]-'a']++;
            }
        }

        int output = 0;

        for (int i = 0; i < 26; i++)
        {
            if (upperCase[i] > 0 && lowerCase[i] > 0)
            {
                output++;
            }
        }

        return output;
    }
};