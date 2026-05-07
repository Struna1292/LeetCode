class Solution {
public:
    int reverse(int n) {
        int curr = 0;

        while (n > 0) {
            int digit = n % 10;
            n /= 10;

            curr *= 10;
            curr += digit;
        }

        return curr;
    }

    bool isPrime(int n) {
        if (n == 1) {
            return false;
        }

        for (int i = n-1; i > 1; i--) {
            if (n % i == 0) {
                return false;
            }
        }

        return true;
    }

    int sumOfPrimesInRange(int n) {
        
        int r = reverse(n);

        int left = min(n, r);
        int right = max(n, r);

        int sum = 0;

        for (int i = left; i <= right; i++) {
            if (isPrime(i)) {
                sum += i;
            }
        }

        return sum;
    }
};