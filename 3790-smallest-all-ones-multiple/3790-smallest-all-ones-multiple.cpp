class Solution {
public:
    int minAllOneMultiple(int k) {
        if (k % 2 == 0 || k % 5 == 0) {
            return -1;
        }

        int output = 1;
        int remainder = 1 % k;
        while (remainder != 0) {
            remainder = (remainder * 10 + 1) % k;
            output++;
        }

        return output;
    }
};