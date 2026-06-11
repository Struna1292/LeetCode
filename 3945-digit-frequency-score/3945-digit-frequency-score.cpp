class Solution {
public:
    int digitFrequencyScore(int n) {
        int freq[10] = { 0 };

        while (n > 0) {
            int digit = n % 10;
            freq[digit]++;
            n /= 10;
        }

        int output = 0;
        for (int i = 0; i < 10; i++) {
            output += i * freq[i];
        }

        return output;
    }
};