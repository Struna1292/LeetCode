class Solution {
public:
    int minChanges(int n, int k) {
        
        if (n == k)
        {
            return 0;
        }

        string numN(32, '0');

        int i = 0;

        while (n > 0)
        {
            if ((n & 1) == 1)
            {
                numN[i] = '1';
            }
            n >>= 1;
            i++;
        }

        string numK(32, '0');

        i = 0;

        while (k > 0)
        {
            if ((k & 1) == 1)
            {
                numK[i] = '1';
            }
            k >>= 1;
            i++;
        }

        int output = 0;

        for (i = 0; i < 32; i++)
        {
            if (numN[i] == '0' && numK[i] == '1')
            {
                return -1;
            }
            else if (numN[i] != numK[i])
            {
                output++;
            }
        }

        return output;
    }
};