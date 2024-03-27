class Solution {
public:
    int minOperations(int k) {
        
        int i = 0;

        int output = -1;
        
        while (i <= k)
        {
            int currOperations = i;

            int currValue = i+1;

            float numberOfNums = ceil((float)k / currValue);

            currOperations += numberOfNums - 1;

            if (output == -1 || currOperations < output)
            {
                output = currOperations;
            }

            i++;
        }

        
        return output;
    }
};