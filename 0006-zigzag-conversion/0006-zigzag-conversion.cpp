class Solution {
public:
    string convert(string s, int numRows) {
        
        vector<string> rows(numRows, "");

        int i = 0;
        while (true)
        {
            for (int j = 0; j < numRows; j++)
            {
                rows[j].push_back(s[i]);
                i++;
                if (i == s.length())
                {
                    break;
                }
            }
            if (i == s.length())
            {
                break;
            }

            for (int j = numRows-2; j > 0; j--)
            {
                rows[j].push_back(s[i]);
                i++;
                if (i == s.length())
                {
                    break;
                }
            }
            if (i == s.length())
            {
                break;
            }
        }

        string output;

        for (string curr : rows)
        {
            output += curr;
        }

        return output;
    }
};