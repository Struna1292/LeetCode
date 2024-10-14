class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        
        bool broken[26] = { false };

        for (int i = 0; i < brokenLetters.length(); i++)
        {
            broken[brokenLetters[i] - 'a'] = true;
        }

        bool isBroken = false;

        int output = 0;

        for (int i = 0; i < text.length(); i++)
        {
            if (text[i] != ' ' && broken[text[i]-'a'])
            {
                isBroken = true;
            }
            
            if (text[i] == ' ')
            {
                if (!isBroken)
                {
                    output++;
                }
                else
                {
                    isBroken = false;
                }
            }
        }
        if (!isBroken)
        {
            output++;
        }
        else
        {
            isBroken = false;
        }


        return output;
    }
};