class Solution {
public:
    bool isPrime(int num)
    {
        if (num == 1)
        {
            return false;
        }
        int counter = 0;
        for (int i = 2; i < num; i++)
        {
            if (num % i == 0)
            {
                return false;
            }
        }
        return true;
    }

    vector<int> closestPrimes(int left, int right) {
        
        int first = -1;
        int second = -1;

        int prev = -1;

        for (int i = left; i <= right; i++)
        {
            if (isPrime(i))
            {
                if ((prev != -1 && first == -1) || (prev != -1 && i - prev < first - second))  
                {
                    first = i;
                    second = prev;

                    if (first - second <= 2)
                    {
                        break;
                    }
                }

                prev = i;
            }
        }

        return {second, first};
    }
};