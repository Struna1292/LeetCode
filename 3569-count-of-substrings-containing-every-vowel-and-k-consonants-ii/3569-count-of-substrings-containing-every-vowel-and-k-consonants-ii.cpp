class Solution {
public:
    bool isVowel(char c)
    {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        {
            return true;
        }
        return false;
    }

    bool checkVowelsOccurence(map<char, int>& mp)
    {
        for (auto itr = mp.begin(); itr != mp.end(); itr++)
        {
            if (itr->second == 0)
            {
                return false;
            }
        }

        return true;
    }

    long long countOfSubstrings(string word, int k) {
        map<char, int> currVowels = {
            {'a', 0},
            {'e', 0},
            {'i', 0},
            {'o', 0},
            {'u', 0},
        };

        // find window then reduce the window from left and count

        long long output = 0;
        int consonantCounter = 0;
        int startIndex = 0;
        int combinationCounter = 0;

        for (int i = 0; i < word.length(); i++)
        {

            if (isVowel(word[i]))
            {
                currVowels[word[i]]++;
            }
            else
            {
                consonantCounter++;
            }


            while (consonantCounter > k)
            {
                combinationCounter = 0;
                if (isVowel(word[startIndex]))
                {
                    currVowels[word[startIndex]]--;
                }
                else
                {
                    consonantCounter--;
                }
                startIndex++;
            }

            if (checkVowelsOccurence(currVowels) && consonantCounter == k)
            {
                output++;
                output += combinationCounter;

                while (true)
                {
                    if (isVowel(word[startIndex]))
                    {
                        if (currVowels[word[startIndex]] == 1)
                        {
                            break;
                        }
                        else
                        {
                            currVowels[word[startIndex]]--;
                        }
                    }
                    else
                    {
                        break;
                    }
                    output++;
                    startIndex++;
                    combinationCounter++;
                }
            }

        }

        return output;
    }
};