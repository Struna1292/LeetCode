class Solution {
public:
    string removeTrailingZeros(string num) {

        int i = num.length()-1;
        for (i; i >= 0; i--)
        {
            if (num[i] != '0')
            {
                break;
            }
        }

        string output;
        output.reserve(i);
        for (int j = 0; j < i+1; j++)
        {
            output.push_back(num[j]);
        }

        return output;
    }
};