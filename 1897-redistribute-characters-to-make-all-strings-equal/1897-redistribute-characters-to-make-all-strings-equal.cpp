class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> letters(26, 0);

        for (int i = 0; i < words.size(); i++)
        {
            for (int j = 0; j < words[i].length(); j++)
            {
                letters[words[i][j]-'a']++;
            }
        }

        for (int i = 0; i < 26; i++)
        {
            if (letters[i] > 0 && letters[i] % words.size() != 0)
            {
                return false;
            }
        }

        return true;
    }
};