class Solution {
public:
    bool isVowel(char c)
    {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        {
            return true;
        }
        return false;
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        
        vector<int> prefixSum(words.size(), 0);

        int curr = 0;

        for (int i = 0; i < words.size(); i++)
        {
            if (isVowel(words[i][0]) && isVowel(words[i][words[i].length()-1]))
            {
                curr++;
            }
            prefixSum[i] = curr;
        }

        vector<int> output(queries.size());

        for (int i = 0; i < queries.size(); i++)
        {
            if (queries[i][0] > 0)
            {
                output[i] = prefixSum[queries[i][1]] - prefixSum[queries[i][0]-1];
            }
            else
            {
                output[i] = prefixSum[queries[i][1]];
            }
        }

        return output;
    }   
};