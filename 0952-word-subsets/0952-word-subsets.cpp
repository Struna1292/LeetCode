class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        
        int sumAlph[26] = { 0 }; // hash of all occurrence of words2

        for (int i = 0; i < words2.size(); i++)
        {
            int curr[26] = { 0 };
            for (int j = 0; j < words2[i].length(); j++)
            {
                curr[words2[i][j]-'a']++;
            }

            for (int j = 0; j < 26; j++)
            {
                if (curr[j] > sumAlph[j])
                {
                    sumAlph[j] = curr[j];
                }
            }
        }

        vector<string> output;

        for (int i = 0; i < words1.size(); i++)
        {
            int alph[26] = { 0 };

            for (int j = 0; j < words1[i].length(); j++)
            {
                alph[words1[i][j]-'a']++;
            }

            bool match = true;
            for (int k = 0; k < 26; k++)
            {
                if (alph[k] < sumAlph[k])
                {
                    match = false;
                    break;
                }
            }
            

            if (match)
            {
                output.push_back(words1[i]);
            }
        }

        return output;
    }
};