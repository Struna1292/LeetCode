class Solution {
public:
    string reversePrefix(string word, char ch) {

        for (int i = 0; i < word.length(); i++)
        {
            if (word[i] == ch)
            {
                int j = 0;
                while (j < i)
                {
                    swap(word[i], word[j]);
                    j++;
                    i--;
                }
                break;
            }
        }
        return word;
    }
};