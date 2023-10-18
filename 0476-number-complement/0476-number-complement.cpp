class Solution {
public:
    int findComplement(int num) {
        if (num == 0)
        {
            return 1;
        }

        string binNum;
        while (num > 0)
        {
            if ((num & 1) == 1)
            {
                binNum.push_back('1');
            }
            else
            {
                binNum.push_back('0');
            }
            num >>= 1;
        }

        int output = 0;
        for (int i = binNum.length()-1; i >= 0; i--)
        {
            if (binNum[i] == '0')
            {
                output |= 1;
            }
            
            if (i != 0)
                output <<= 1;
        }


        return output;
    }
};