class Solution {
public:
    int countEven(int num) {
        
        int output = 0;
        for (int i = 1; i <= num; i++)
        {
            int curr = i;
            int currSum = 0;

            while (curr > 0)
            {
                currSum += (curr % 10);
                curr /= 10;
            }

            if (currSum % 2 == 0)
            {
                output++;
            }
        }

        return output;
    }
};