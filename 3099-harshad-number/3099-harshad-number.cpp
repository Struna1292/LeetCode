class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int num = x;

        int sum = 0;

        while (num > 0)
        {
            sum += (num % 10);
            num /= 10;
        }

        if (x % sum == 0)
        {
            return sum;
        }

        return -1;
    }
};