class Solution {
public:
    int numberOfSteps(int num) {
        int counter = 0;

        while (num > 0)
        {
            counter++;
            if (num % 2 == 0)
            {
                num /= 2;
            }
            else
            {
                num -= 1;
            }
        }

        return counter;
    }
};