class Solution {
public:
    bool isHappy(int n) {
        int sumOfDigits = 0;
        vector<int> check;
        while (sumOfDigits != 1)
        {
            sumOfDigits = 0;
            while (n != 0)
            {
                if (n < 10)
                {
                    sumOfDigits += n * n;
                }
                else
                {
                    sumOfDigits += (n % 10) * (n % 10);
                }
                n = n / 10;
            }
            n = sumOfDigits;
            for (int i = 0; i < check.size(); i++)
            {
                if (n == check[i])
                {
                    return false;
                }
            }
            check.push_back(n);
        }
        return true;
    }
};