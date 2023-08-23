class Solution {
public:
    int pivotInteger(int n) {
        int left = 0;
        int right = n;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            int sum = 0;
            for (int i = mid; i <= n; i++)
            {
                sum += i;
            }

            for (int i = mid; i > 0; i--)
            {
                sum -= i;
            }

            if (sum == 0)
            {
                return mid;
            }
            
            if (sum > 0)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }   
        }

        return -1;
    }
};