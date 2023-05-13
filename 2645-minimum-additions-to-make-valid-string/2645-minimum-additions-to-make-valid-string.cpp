class Solution {
public:
    int addMinimum(string word) {

        int output = 0;
        
        int i = 0;
        while (i < word.length())
        {
            if (word[i] == 'a')
            {
                if (i+1 < word.length() && word[i+1] == 'b')
                {
                    i++;
                    if (i+1 < word.length() && word[i+1] == 'c')
                    {
                        i++;
                    }
                    else
                    {
                        output++;
                    }
                }
                else if (i+1 < word.length() && word[i+1] == 'c')
                {
                    output += 1;
                    i++;
                }
                else
                {
                    output += 2;
                }
            }
            else
            {
                if (word[i] == 'b' && i+1 < word.length() && word[i+1] == 'c')
                {
                    output += 1;
                    i++;
                }
                else
                {
                    output += 2;
                }
            }
            i++;
        }

        return output;
    }
};