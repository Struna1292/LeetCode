class Solution {
public:
    vector<int> evenOddBit(int n) {
        
        int even = 0;
        int odd = 0;
        int i = 1;
        while (n != 0)
        {
            if (i % 2 == 0)
            {
                if (n & 1)
                {
                    odd++;
                }
            }
            else
            {
                if (n & 1)
                {
                    even++;
                }
            }
            i++;
            n >>= 1;
        }
        return {even, odd};
    }
};