class Solution {
public:
    int tribonacci(int n) {
        int a = 0;
        int b = 1;
        int c = 1;

        if (n == 0)
        {
            return 0;
        }
        else if (n == 1)
        {
            return 1;
        }
        else if (n == 2)
        {
            return 1;
        }
        else
        {
            n -= 2;
        }

        while (n > 0)
        {
            a += b + c;

            int tempB = b;

            b = c;
            c = a;
            a = tempB;

            n--;
        }

        return c;
    }
};