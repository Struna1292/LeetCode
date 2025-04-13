class Solution {
public:
    long long myPower(long long base, long long exp, long long mod) 
    {
        long long output = 1;
        base = base % mod;

        while (exp > 0) 
        {
            if (exp % 2 == 1) 
            {
                output = (output * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }

        return output;
    }


    int countGoodNumbers(long long n) {

        // you have only 5 options on even positions
        // you have only 4 options on odd positions
        // now we get number of even positions and then 5 to power of our count
        // then we do the same with odd

        long long even = n/2;
        long long odd = even;

        if (n % 2 != 0)
        {
            even++;
        }

        return (int)(myPower(5, even, 1000000007) * myPower(4, odd, 1000000007) % 1000000007);
    }
};