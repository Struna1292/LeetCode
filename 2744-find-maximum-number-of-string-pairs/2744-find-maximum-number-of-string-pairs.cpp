class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        
        int output = 0;

        for (int i = 0; i < words.size(); i++)
        {
            for (int j = i+1; j < words.size(); j++)
            {
                if (words[i].length() == words[j].length())
                {
                    int k = 0;
                    int l = words[j].length()-1;
                    while (k < words[i].length() && words[i][k] == words[j][l])
                    {
                        k++;
                        l--;
                    }

                    if (l == -1)
                    {
                        output++;
                    }
                }
            }
        }

        return output;
    }
};