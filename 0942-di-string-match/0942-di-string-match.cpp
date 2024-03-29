class Solution {
public:
    vector<int> diStringMatch(string s) {

        vector<int> output;

        int i = 0;

        int j = s.length();

        for (int k = 0; k < s.length(); k++)
        {
            if (s[k] == 'I')
            {
                output.push_back(i);
                i++;
            }
            else
            {
                output.push_back(j);
                j--;
            }
        }

        output.push_back(i);

        return output;
    }
};