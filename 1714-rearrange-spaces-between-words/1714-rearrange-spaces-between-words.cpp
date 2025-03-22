class Solution {
public:
    string reorderSpaces(string text) {
        
        int spaceCounter = 0;
        
        string curr;
        vector<string> words;

        for (int i = 0; i < text.length(); i++)
        {
            if (text[i] == ' ')
            {
                spaceCounter++;

                if (curr != "")
                {
                    words.push_back(curr);
                    curr = "";
                }
            }
            else
            {
                curr.push_back(text[i]);
            }
        }
        if (curr != "")
        {
            words.push_back(curr);
        }

        if (spaceCounter == 0)
        {
            return text;
        }

        if (words.size() == 1)
        {
            curr = "";
            for (int i = 0; i < words[0].length(); i++)
            {
                curr.push_back(words[0][i]);
            }
            for (int i = 0; i < spaceCounter; i++)
            {
                curr.push_back(' ');
            }
            return curr;
        }

        int gap = spaceCounter / (words.size() - 1);

        string output;

        for (int i = 0; i < words.size(); i++)
        {

            for (int j = 0; j < words[i].length(); j++)
            {
                output.push_back(words[i][j]);
            }

            if (i != words.size()-1)
            {
                for (int j = 0; j < gap; j++)
                {
                    output.push_back(' ');
                }
            }
            else
            {
                int rest = spaceCounter % (words.size() - 1);
                for (int j = 0; j < rest; j++)
                {
                    output.push_back(' ');
                }
            }
        }

        return output;
    }
};