class Solution {
public:

    int removeAlmostEqualCharacters(string word) {

        int output = 0;

        for (int i = 1; i < word.length(); i++)
        {
            if (word[i-1] == word[i] || word[i-1] == word[i]-1 || word[i-1]-1 == word[i])
            {
                i++;
                output++;
            }
        }

        return output;
    }
};