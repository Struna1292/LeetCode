class Solution {
public:
    int minimumOneBitOperations(int n) {

        int sum1 = 0;
        int sum2 = 0;
        int i = 0;
        bool check = true;

        int output = 0;

        while (n > 0)
        {
            if ((n & 1) == 1)
            {
                if (check)
                {
                    sum1 += pow(2,i+1)-1;
                    check = false;
                }
                else
                {
                    sum2 += pow(2,i+1)-1;
                    check = true;
                } 
            }


            n >>= 1;
            if (n == 0)
            {
                if (sum1 > sum2)
                {
                    output = sum1 - sum2;
                }
                else
                {
                    output = sum2 - sum1;
                }
            }
            i++;
        }

        
        return output;
    }
};