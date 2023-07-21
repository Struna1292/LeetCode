class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<vector<int>> alphabets(words.size(), vector<int>(26, 0));

        for (int i = 0; i < words.size(); i++)
        {
            for (int j = 0; j < words[i].length(); j++)
            {
                alphabets[i][words[i][j] - 'a']++;
            }
        }

        vector<string> output;
        for (int i = 0; i < 26; i++)
        {
            int min = alphabets[0][i];
            for (int j = 0; j < words.size(); j++)
            {
                if (min > alphabets[j][i])
                {
                    min = alphabets[j][i];
                }
            }

            char c = i + 'a';
            string s;
            s.push_back(c);
            for (int j = 0; j < min; j++)
            {
                output.push_back(s);
            }
        }

        return output;
    }
};