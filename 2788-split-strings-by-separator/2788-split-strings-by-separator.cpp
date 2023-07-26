class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        
        vector<string> output;

        for (int i = 0; i < words.size(); i++)
        {
            string curr;
            string empty;
            for (int j = 0; j < words[i].length(); j++)
            {
                if (words[i][j] == separator && curr != empty)
                {
                    output.push_back(curr);
                    curr = empty;
                }
                else if (words[i][j] != separator)
                {
                    curr.push_back(words[i][j]);
                }
            }
            if (curr != empty)
                output.push_back(curr);
        }

        return output;
    }
};