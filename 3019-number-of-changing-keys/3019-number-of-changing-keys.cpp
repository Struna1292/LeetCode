class Solution {
public:
    int countKeyChanges(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower); 

        int output = 0;

        for (int i = 0; i < s.length()-1; i++)
        {
            if (s[i] != s[i+1])
            {
                output++;
            }
        }

        return output;
    }
};