class Solution {
public:
    bool checkPowersOfThree(int n) {

        int curr = 3;
        while (curr < n)
        {
            curr *= 3;
        }
        if (curr == n)
        {
            return true;
        }

        curr /= 3;

        while (true)
        {
            if (curr <= n)
            {
                n -= curr;
            }
            curr /= 3;
            if (curr == 0 || n == 0)
            {
                break;
            }
        }

        if (n == 0)
        {
            return true;
        }

        return false;
    }
};