class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        
        int output = -1;

        vector<vector<int>> letterIndexes(26, vector<int>());

        for (int i = 0; i < s.length(); i++)
        {
            letterIndexes[s[i]-'a'].push_back(i);
        }

        for (int i = 0; i < 26; i++)
        {
            if (letterIndexes[i].size() >= 2)
            {
                if (letterIndexes[i][letterIndexes[i].size()-1] - (letterIndexes[i][0]+1) > output)
                {
                    output = letterIndexes[i][letterIndexes[i].size()-1] - (letterIndexes[i][0]+1);
                }
            }
        }

        return output;
    }
};