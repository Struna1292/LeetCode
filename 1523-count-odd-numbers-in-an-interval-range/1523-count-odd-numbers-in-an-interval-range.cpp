class Solution {
public:
    int countOdds(int low, int high) {

        int amount = high + 1 - low;
        int odds = amount / 2;

        if (amount % 2 != 0 && low % 2 != 0) {
            odds++;
        }

        return odds;
    }
};