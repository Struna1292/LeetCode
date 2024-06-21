class Solution {
public:
    int xorOperation(int n, int start) {
        
        int curr = 0;

        int output = start;

        for (int i = 0; i < n; i++)
        {
            curr = start + (2 * i);

            if (i > 0)
            {
                output ^= curr;
            }
        }

        return output;
    }
};