class Solution {
public:
    int minimumOneBitOperations(int n) {

        string s;

        while (n > 0)
        {
            if ((n & 1) == 1)
            {
                s.push_back('1');
            }
            else
            {
                s.push_back('0');
            }
            n >>= 1;
        }

        int output = 0;
        bool plus = true;

        for (int i = s.length()-1; i >= 0; i--)
        {
            if (s[i] == '1')
            {
                if (plus)
                {
                    output += pow(2,i+1)-1;
                    plus = false;
                }
                else
                {
                    output -= pow(2,i+1)-1;
                    plus = true;
                }
            }
        }

        return output;
    }
};