class Solution {
public:
    int maxScore(string s) {

        if (s.length() == 2)
        {
            int curr = 0;
            
            if (s[0] == '0')
            {
                curr++;
            }

            if (s[1] == '1')
            {
                curr++;
            }

            return curr;
        }
        
        vector<int> prefix(s.length(), 0);

        int curr = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '0')
            {
                curr++;
            }
            prefix[i] = curr;
        }


        curr = 0;

        if (s[s.length()-1] == '1')
        {
            curr++;
        }

        int output = 0;
        for (int i = s.length()-2; i >= 1; i--)
        {
            if (s[i] == '1')
            {
                curr++;
            }

            if (curr + prefix[i] > output)
            {
                output = curr + prefix[i];
            }
        }

        return output;
    }
};