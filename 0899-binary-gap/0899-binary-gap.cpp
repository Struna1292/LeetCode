class Solution {
public:
    int binaryGap(int n) {
        
        int output = 0;
        int counter = 0;

        int ones = 0;

        while (n > 0)
        {
            if ((n & 1) == 1)
            {
                if (counter > output && ones >= 1)
                {
                    output = counter;
                }
                counter = 0;

                ones++;
            }
            else
            {
                counter++;
            }  
            n >>= 1;
        }

        if (ones <= 1)
        {
            return 0;
        }

        return output+1;
    }
};