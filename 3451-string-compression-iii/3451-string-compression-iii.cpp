class Solution {
public:
    string compressedString(string word) {

        int counter = 1;
        char prev = word[0];

        string output;

        for (int i = 1; i < word.length(); i++)
        {
            if (word[i] != prev || counter == 9)
            {
                output.push_back('0'+counter);
                output.push_back(prev);

                counter = 1;
                prev = word[i];
            }
            else
            {
                counter++;
            }
        }
        output.push_back('0'+counter);
        output.push_back(prev);

        return output;
    }
};