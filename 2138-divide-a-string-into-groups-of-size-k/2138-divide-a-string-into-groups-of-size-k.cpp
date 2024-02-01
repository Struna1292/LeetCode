class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> output;

        for (int i = 0; i < s.length(); i+=k)
        {
            string curr;
            int border = i + k;
            if (border > s.length())
            {
                border = s.length();
            }

            for (int j  = i; j < border; j++)
            {
                curr.push_back(s[j]);
            }

            while (curr.length() != k)
            {
                curr.push_back(fill);
            }

            output.push_back(curr);
        }
        
        return output;
    }
};