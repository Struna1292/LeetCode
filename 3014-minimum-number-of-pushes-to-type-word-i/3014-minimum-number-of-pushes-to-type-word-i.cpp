class Solution {
public:
    int minimumPushes(string word) {
        int times = 1;
        
        int letters = word.length();

        int output = 0;

        while (letters > 0)
        {
            if (letters > 8)
            {
                output += 8 * times;
                letters -= 8;
            }
            else
            {
                output += letters * times;
                letters = 0;
            }

            times++;
        }

        return output;
    }
};