class Solution {
public:
    string largestOddNumber(string num) {
        string output = "";

        int i = num.length()-1;

        for (i; i >= 0; i--)
        {
            if ((num[i] - '0') % 2 != 0)
            {
                break;
            }
        }

        for (int j = 0; j <= i; j++)
        {
            output.push_back(num[j]);
        }

        return output;
    }
};