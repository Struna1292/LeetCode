class Solution {
public:
    int similarPairs(vector<string>& words) {
        vector<vector<bool>> letters(words.size(), vector<bool>(26, false));

        for (int i = 0; i < words.size(); i++)
        {
            for (int j = 0; j < words[i].length(); j++)
            {
                letters[i][words[i][j]-'a'] = true;
            }
        }

        int output = 0;

        for (int i = 0; i < words.size(); i++)
        {
            for (int j = i+1; j < words.size(); j++)
            {
                int k = 0;
                while (k < 26 && letters[i][k] == letters[j][k])
                {
                    k++;
                }

                if (k == 26)
                {
                    output++;
                }
            }
        }

        return output;
    }
};