class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        
        int i = 0;

        while (i < s1.length() && i < s2.length() && i < s3.length() && s1[i] == s2[i] && s2[i] == s3[i] && s1[i] == s3[i])
        {
            i++;
        }

        if (i == 0)
        {
            return -1;
        }

        int output = (s1.length() - i) + (s2.length() - i) + (s3.length() - i);

        return output;
    }
};