class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {

        vector<vector<int>> patternIndexes(26, vector<int>());

        for (int i = 0; i < pattern.length(); i++)
        {
            patternIndexes[pattern[i]-'a'].push_back(i);
        }

        vector<string> output;

        for (int i = 0; i < words.size(); i++)
        {
            vector<vector<int>> currIndexes(26, vector<int>());

            for (int j = 0; j < words[i].length(); j++)
            {
                currIndexes[words[i][j]-'a'].push_back(j);
            }

            int check1 = 0;
            int check2 = 0;
            for (int j = 0; j < 26; j++)
            {
                if (patternIndexes[j].size() > 0)
                {
                    check1++;
                    for (int k = 0; k < 26; k++)
                    {
                        if (patternIndexes[j].size() == currIndexes[k].size())
                        {
                            int counter = 0;
                            for (int l = 0; l < patternIndexes[j].size(); l++)
                            {
                                if (patternIndexes[j][l] == currIndexes[k][l])
                                {
                                    counter++;
                                }
                                else
                                {
                                    counter = 0;
                                    break;
                                }
                            }

                            if (counter == patternIndexes[j].size())
                            {
                                check2++;
                                break;
                            }
                        }
                    }
                }
            }

            if (check1 == check2)
            {
                output.push_back(words[i]);
            }

        }

        return output;
    }
};