class Solution {
public:
    int compress(vector<char>& chars) {
        
        int counter = 1;
        char prev = chars[0];
        vector<char> replace;

        for (int i = 1; i < chars.size(); i++)
        {
            if (chars[i] != prev)
            {
                replace.push_back(prev);
                if (counter != 1)
                {
                    string num = to_string(counter);
                    for (int j = 0; j < num.length(); j++)
                    {
                        replace.push_back(num[j]);
                    }
                }
                counter = 1;
                prev = chars[i];
            }
            else
            {
                counter++;
            }
        }

        replace.push_back(prev);
        if (counter != 1)
        {
            string num = to_string(counter);
            for (int j = 0; j < num.length(); j++)
            {
                replace.push_back(num[j]);
            }
        }

        chars = replace;

        return chars.size();
    }
};