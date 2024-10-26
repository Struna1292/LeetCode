class Solution {
public:
    int possibleStringCount(string word) {
        
        int output = 1;

        int prev = word[0];
        int counter = 1;

        for (int i = 1; i < word.length(); i++)
        {
            if (word[i] == prev)
            {
                counter++;
            }
            else
            {
                output += counter-1;

                counter = 1;
                prev = word[i];
            }
        }
        output += counter-1;

        return output;
    }
};