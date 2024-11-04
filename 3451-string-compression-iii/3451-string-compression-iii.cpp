class Solution {
public:
    string compressedString(string word) {
        string output;

        int counter = 1;
        int prev = word[0];

        for (int i = 1; i < word.length(); i++)
        {
            if (word[i] == prev)
            {
                counter++;
            }
            else
            {
                while (counter > 9)
                {
                    counter -= 9;
                    output.push_back('9');
                    output.push_back(prev);
                }

                if (counter > 0)
                {
                    output.push_back('0'+counter);
                    output.push_back(prev);
                }

                counter = 1;
                prev = word[i];
            }
        }

        while (counter > 9)
        {
            counter -= 9;
            output.push_back('9');
            output.push_back(prev);
        }

        if (counter > 0)
        {
            output.push_back('0'+counter);
            output.push_back(prev);
        }

        return output;
    }
};