class Solution {
public:
    string reversePrefix(string word, char ch) {
        
        int index = -1;

        for (int i = 0; i < word.length(); i++)
        {
            if (word[i] == ch)
            {
                index = i;
                break;
            }
        }

        if (index != -1)
        {
            int i = 0;
            while (i < index)
            {
                swap(word[i], word[index]);
                i++;
                index--;
            }
        }

        return word;
    }
};