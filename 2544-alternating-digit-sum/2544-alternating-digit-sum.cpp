class Solution {
public:
    int alternateDigitSum(int n) {
        string num = to_string(n);
        int output = 0;

        for (int i = 0; i < num.length(); i++)
        {
            int curr = num[i] - '0';
            if ((i+1) % 2 == 0)
            {
                curr *= -1;
            }
            output += curr;
        }

        return output;
    }
};