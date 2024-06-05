class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        
        vector<vector<int>> alph(words.size(), vector(26, 0));

        for (int i = 0; i < words.size(); i++)
        {
            for (int j = 0; j < words[i].length(); j++)
            {
                alph[i][words[i][j]-'a']++;
            }
        }

        vector<string> output;

        for (int i = 0; i < 26; i++)
        {

            int lowest = alph[0][i];

            for (int j = 1; j < alph.size(); j++)
            {
                if (alph[j][i] < lowest)
                {
                    lowest = alph[j][i];
                }
            }

            string curr = "";

            curr += 'a'+i;

            for (int j = 0; j < lowest; j++)
            {
                output.push_back(curr);
            }
        }

        return output;
    }
};