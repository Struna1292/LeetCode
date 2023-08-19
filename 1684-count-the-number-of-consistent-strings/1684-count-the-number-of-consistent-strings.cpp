class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int alph[26] = { 0 };

        for (int i = 0; i < allowed.length(); i++)
        {
            alph[allowed[i] - 'a']++;
        }
        
        int output = 0;

        for (int i = 0; i < words.size(); i++)
        {
            bool consistent = true;
            for (int j = 0; j < words[i].length(); j++)
            {
                if (alph[words[i][j]-'a'] == 0)
                {
                    consistent = false;
                    break;
                }
            }
            if (consistent)
                output++;
        }

        return output;
    }
};