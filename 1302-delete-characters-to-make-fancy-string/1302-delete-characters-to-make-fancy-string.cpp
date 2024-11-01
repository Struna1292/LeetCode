class Solution {
public:
    string makeFancyString(string s) {
        
        string output;

        char prev = s[0];
        int counter = 1;

        for (int i = 1; i < s.length(); i++)
        {
            if (s[i] == prev)
            {
                counter++;
            }
            else
            {
                if (counter > 2)
                {
                    counter = 2;
                }

                for (int j = 0; j < counter; j++)
                {
                    output.push_back(prev);
                }

                prev = s[i];
                counter = 1;
            }
        }
        if (counter > 2)
        {
            counter = 2;
        }

        for (int j = 0; j < counter; j++)
        {
            output.push_back(prev);
        }

        return output;
    }
};