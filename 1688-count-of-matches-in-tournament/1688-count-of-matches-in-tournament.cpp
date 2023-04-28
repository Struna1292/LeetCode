class Solution {
public:
    int numberOfMatches(int n) {
        int matchSum = 0;
        while (n > 1)
        {
            if (n % 2 != 0)
            {
                n--;
                n /= 2;
                matchSum += n;
                n++;
            }
            else
            {
                n /= 2;
                matchSum += n;
            }
        }
        return matchSum;
    }
};