class Solution {
public:
    long long flowerGame(int n, int m) {
        // we can see that to win alice need to take last flower
        // so the sum of the flowers needs to be odd
        // sum of two nums is odd if they are different parity

        // now to count all the possibilities
        // multiply all even by all odd from lines

        long long evenN = n / 2;
        long long oddN = n / 2;
        if (n % 2 != 0) {
            oddN++;
        }

        long long evenM = m / 2;
        long long oddM = m / 2;
        if (m % 2 != 0) {
            oddM++;
        }

        return evenN * oddM + oddN * evenM;
    }
};