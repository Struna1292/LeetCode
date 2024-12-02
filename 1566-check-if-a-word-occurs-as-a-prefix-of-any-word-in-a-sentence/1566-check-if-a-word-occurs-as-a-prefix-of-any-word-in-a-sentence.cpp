class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {

        int wordCounter = 0;

        for (int i = 0; i < sentence.length(); i++)
        {
            if (sentence[i] == ' ' || i == 0)
            {
                wordCounter++;
                int border = i + searchWord.length()+1;
                if (i == 0)
                {
                    border--;
                }
                if (border <= sentence.length())
                {
                    int k = 0;
                    bool match = true;
                    int j = i + 1;
                    if (i == 0)
                    {
                        j--;
                    }

                    for (j; j < border; j++)
                    {
                        if (sentence[j] != searchWord[k])
                        {
                            match = false;
                            break;
                        }
                        k++;
                    }

                    if (match)
                    {
                        if (i == 0)
                        {
                            return 1;
                        }
                        return wordCounter;
                    }
                }
            }
        }

        return -1;
    }
};