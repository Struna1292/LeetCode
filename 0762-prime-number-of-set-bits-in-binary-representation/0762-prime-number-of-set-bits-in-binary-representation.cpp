class Solution {
public:
    bool isPrime(int num) {
        if (num == 2 || num == 3 || num == 5 || num == 7 || num == 11 || num == 13 || num == 17 || num == 19) {
            return true;
        }

        return false;
    }

    int countPrimeSetBits(int left, int right) {
        
        int output = 0;

        for (int i = left; i <= right; i++) {
            int curr = i;
            int counter = 0;

            while (curr > 0) {
                if ((curr & 1) == 1) {
                    counter++;
                }

                curr >>= 1;
            }

            if (isPrime(counter)) {
                output++;
            }
        }

        return output;
    }
};