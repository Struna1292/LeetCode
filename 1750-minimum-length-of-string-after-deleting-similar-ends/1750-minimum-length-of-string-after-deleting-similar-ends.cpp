class Solution {
public:
    int minimumLength(string s) {
        int i = 0;
        int j = s.length()-1;

        while (i < j && s[i] == s[j])
        {
            char curr = s[i];

            while (i < j && s[i] == curr)
            {
                i++;
            }

            if (i == j)
            {
                return 0;
            }

            while (i < j && s[j] == curr)
            {
                j--;
            }

            if (i+1 == j && s[i] == s[j])
            {
                return 0;
            }
        }

        return j - i + 1;
    }
};