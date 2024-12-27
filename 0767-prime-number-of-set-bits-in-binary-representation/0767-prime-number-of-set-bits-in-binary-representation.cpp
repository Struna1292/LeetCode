class Solution {
public:
    bool isPrime(int num)
    {
        if (num <= 1)
        {
            return false;
        }

        for (int i = 2; i < num; i++)
        {
            if (num % i == 0)
            {
                return false;
            }
        }

        return true;
    }

    int countPrimeSetBits(int left, int right) {
        
        int output = 0;

        for (int i = left; i <= right; i++)
        {
            int curr = i;

            int counter = 0;

            while (curr > 0)
            {
                if ((curr & 1) == 1)
                {
                    counter++;
                }

                curr >>= 1;
            }

            if (isPrime(counter))
            {
                output++;
            }
        }

        return output;
    }
};