class Solution {
public:
    bool isPowerOfFour(int n) {

        int num = 1;
        while (num < n)
        {
            if ((long)num*4 > 2147483647)
            {
                return false;
            }
            num *= 4;
        }

        if (num == n)
        {
            return true;
        }

        return false;
    }
};