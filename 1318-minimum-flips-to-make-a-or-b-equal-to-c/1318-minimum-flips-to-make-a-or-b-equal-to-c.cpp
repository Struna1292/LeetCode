class Solution {
public:
    int minFlips(int a, int b, int c) {
        
        int counter = 0;
        while (c > 0)
        {
            bool cBit = (c & 1);
            bool aBit = 0;
            if (a > 0)
            {
                aBit = (a & 1);
                a >>= 1;
            }
            bool bBit = 0;
            if (b > 0)
            {
                bBit = (b & 1);
                b >>= 1;
            }
            c >>= 1;

            if (cBit == 1)
            {
                if (aBit == 0 && bBit == 0)
                {
                    counter++;
                }
            }
            else
            {
                if (aBit == 1)
                {
                    counter++;
                }
                if (bBit == 1)
                {
                    counter++;
                }
            }
        }

        while (a > 0)
        {
            if (a & 1 == 1)
            {
                counter++;
            }
            a >>= 1;
        }

        while (b > 0)
        {
            if (b & 1 == 1)
            {
                counter++;
            }
            b >>= 1;
        }

        return counter;
    }
};