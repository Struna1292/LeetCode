class Solution {
public:

    bool isVowel(char c)
    {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        {
            return true;
        }
        return false;
    }

    string toGoatLatin(string sentence) {

        string curr = "";
        string empty = "";

        string output;
        
        int counter = 0;
        for (int i = 0; i < sentence.length(); i++)
        {
            if (sentence[i] != ' ')
            {
                curr.push_back(sentence[i]);
            }
            else
            {
                counter++;
                if (isVowel(curr[0]))
                {
                    output.append(curr);
                }
                else
                {
                    for (int j = 1; j < curr.length(); j++)
                    {
                        output.push_back(curr[j]);
                    }
                    output.push_back(curr[0]);
                }

                output.append("ma");
                for (int j = 0; j < counter; j++)
                {
                    output.push_back('a');
                }
                output.push_back(' ');
                curr = empty;
            }
        }

        counter++;
        if (isVowel(curr[0]))
        {
            output.append(curr);
        }
        else
        {
            for (int j = 1; j < curr.length(); j++)
            {
                output.push_back(curr[j]);
            }
            output.push_back(curr[0]);
        }

        output.append("ma");
        for (int j = 0; j < counter; j++)
        {
            output.push_back('a');
        }

        return output;
    }
};