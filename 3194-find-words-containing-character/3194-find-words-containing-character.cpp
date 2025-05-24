class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        
        vector<int> output;

        for (int i = 0; i < words.size(); i++)
        {
            for (char c : words[i])
            {
                if (c == x)
                {
                    output.push_back(i);
                    break;
                }
            }
        }

        return output;
    }
};