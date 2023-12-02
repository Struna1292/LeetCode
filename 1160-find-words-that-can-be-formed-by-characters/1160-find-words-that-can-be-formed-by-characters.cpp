class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> letters(26, 0);

        for (int i = 0; i < chars.length(); i++)
        {
            letters[chars[i]-'a']++;
        }
        
        int output = 0;

        for (int i = 0; i < words.size(); i++)
        {
            vector<int> curr(26, 0);
            for (int j = 0; j < words[i].length(); j++)
            {
                curr[words[i][j]-'a']++;
            }

            bool check = true;
            for (int j = 0; j < 26; j++)
            {
                if (letters[j] < curr[j])
                {
                    check = false;
                    break;
                }
            }

            if (check)
            {
                output += words[i].length();
            }
        }

        return output;
    }
};