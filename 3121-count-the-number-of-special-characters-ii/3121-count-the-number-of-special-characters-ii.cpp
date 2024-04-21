class Solution {
public:
    int numberOfSpecialChars(string word) {

        vector<vector<int>> lowerCase(26, vector<int>());
        vector<vector<int>> upperCase(26, vector<int>());

        for (int i = 0; i < word.length(); i++)
        {
            if (word[i] >= 65 && word[i] <= 90)
            {
                upperCase[word[i]-'A'].push_back(i);
            }
            else
            {
                lowerCase[word[i]-'a'].push_back(i);
            }
        }

        int output = 0;

        for (int i = 0; i < 26; i++)
        {
            if (lowerCase[i].size() >= 1 && upperCase[i].size() >= 1 && lowerCase[i][lowerCase[i].size()-1] < upperCase[i][0])
            {
                output++;
            }
        }

        return output;
    }
};