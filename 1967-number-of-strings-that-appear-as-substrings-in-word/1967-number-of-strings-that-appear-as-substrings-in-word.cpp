class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int output = 0;

        for (int i = 0; i < patterns.size(); i++)
        {
            if (word.find(patterns[i]) != std::string::npos)
            {
                output++;
            }
        }

        return output;
    }
};