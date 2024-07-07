class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        
        int output = 0;

        int emptyBottles = 0;

        int leftBottles = 0;

        int fullBottles = numBottles;

        while (true)
        {
            output += fullBottles;

            emptyBottles = fullBottles + leftBottles;

            leftBottles = emptyBottles % numExchange;

            fullBottles = emptyBottles / numExchange;

            if ((fullBottles+leftBottles) < numExchange)
            {
                output += fullBottles;
                break;
            }
        }

        return output;
    }
};