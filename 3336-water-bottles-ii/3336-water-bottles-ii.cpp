class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        
        int output = 0;
        int fullBottles = numBottles;
        int emptyBottles = 0;

        while (fullBottles > 0) {
            
            output += fullBottles;

            emptyBottles += fullBottles;

            fullBottles = 0;

            while (emptyBottles >= numExchange) {
                fullBottles++;
                emptyBottles -= numExchange;
                numExchange++;
            }
        }

        return output;
    }
};