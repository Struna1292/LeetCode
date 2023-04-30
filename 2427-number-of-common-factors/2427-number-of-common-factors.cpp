class Solution {
public:
    int commonFactors(int a, int b) {
        if (a < b)
        {
            int temp = a;
            a = b;
            b = temp;
        }
        int counter = 0;
        for (int i = 1; i <= b; i++)
        {
            if (b % i == 0 && a % i == 0)
            {
                counter++;
            }
        }
        return counter;
    }
};