class Solution {
public:
    int maxProduct(vector<string>& words) {
        
        int output = 0;

        for (int i = 0; i < words.size(); i++)
        {
            bool alph1[26] = { false };

            for (int j = 0; j < words[i].length(); j++)
            {
                alph1[words[i][j]-'a'] = true;
            }

            for (int j = i+1; j < words.size(); j++)
            {
                if (words[i].length() * words[j].length() > output)
                {
                    bool alph2[26] = { false };

                    for (int k = 0; k < words[j].length(); k++)
                    {
                        alph2[words[j][k]-'a'] = true;
                    }

                    bool match = true;

                    for (int k = 0; k < 26; k++)
                    {
                        if (alph1[k] && alph2[k])
                        {   
                            match = false;
                        }
                    }

                    if (match)
                    {
                        output = words[i].length() * words[j].length();
                    }
                }
            }
        }

        return output;
    }
};