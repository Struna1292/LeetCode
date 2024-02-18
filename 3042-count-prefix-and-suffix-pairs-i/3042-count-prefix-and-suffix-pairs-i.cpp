class Solution {
public:
    bool isPrefixAndSuffix(string &str1, string &str2)
    {
        if (str2.length() < str1.length())
        {
            return false;
        }

        for (int i = 0; i < str1.length(); i++)
        {
            if (str1[i] != str2[i])
            {
                return false;
            }
        }

        int j = str2.length()-1;
        for (int i = str1.length()-1; i >= 0; i--)
        {
            if (str1[i] != str2[j])
            {
                return false;
            }
            j--;
        }

        return true;
    }

    int countPrefixSuffixPairs(vector<string>& words) {
        
        int output = 0;

        for (int i = 0; i < words.size(); i++)
        {
            for (int j = i+1; j < words.size(); j++)
            {
                if (isPrefixAndSuffix(words[i], words[j]))
                {
                    output++;
                }
            }
        }

        return output;
    }
};