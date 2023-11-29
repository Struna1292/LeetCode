class Solution {
public:
    int hammingWeight(uint32_t n) {
        int output = 0;

        while (n > 0)
        {
            if ((n & 1) == 1)
            {
                output++;
            }
            n >>= 1;
        }

        return output;
    }
};