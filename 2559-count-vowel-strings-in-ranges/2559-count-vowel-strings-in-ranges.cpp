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
        
        vector<int> prefixSum = {0};
        int prev = 0;
        for (int i = 0; i < words.size(); i++)
        {
            if (isVowel(words[i][0]) && isVowel(words[i][words[i].length()-1]))
            {
                prev += 1;
                prefixSum.push_back(prev);
            }
            else
            {
                prefixSum.push_back(prev);
            }
        }


        vector<int> output;
        for (int i = 0; i < queries.size(); i++)
        {
            output.push_back(prefixSum[queries[i][1]+1] - prefixSum[queries[i][0]]);
        }

        return output;
    }
};