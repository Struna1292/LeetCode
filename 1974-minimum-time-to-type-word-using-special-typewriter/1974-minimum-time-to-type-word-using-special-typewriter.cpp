class Solution {
public:
    int minTimeToType(string word) {
        int output = 0;

        char prev = 'a';

        for (int i = 0; i < word.length(); i++)
        {
            int right = abs(word[i] - prev);
            int left = 26 - right;

            if (right < left)
            {
                output += right + 1;
            }
            else
            {
                output += left + 1;
            }

            prev = word[i];
        }

        return output;
    }
};