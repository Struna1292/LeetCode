class Solution {
public:
    int maxPower(string s) {
        
        int counter = 1;
        int prev = s[0];

        int output = 1;

        for (int i = 1; i < s.length(); i++)
        {
            if (s[i] == prev)
            {
                counter++;
            }
            else
            {
                prev = s[i];
                if (counter > output)
                {
                    output = counter;
                }
                counter = 1;
            }
        }
        
        if (counter > output)
        {
            output = counter;
        }

        return output;
    }
};