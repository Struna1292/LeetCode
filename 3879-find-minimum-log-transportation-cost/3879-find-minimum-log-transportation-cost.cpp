class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
        
        long long output = 0;

        if (n > k)
        {
            n -= k;
            output += (long long)n* (long long)k;
        }

        if (m > k)
        {
            m -= k;
            output += (long long)m*(long long)k;
        }

        return output;
    }
};