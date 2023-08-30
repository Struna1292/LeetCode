class Solution {
public:
    int accountBalanceAfterPurchase(int purchaseAmount) {
        int remainder = purchaseAmount % 10;
        if (remainder >= 5)
        {
            purchaseAmount += (10 - remainder);
        }
        else
        {
            purchaseAmount -= remainder;
        }

        return 100 - purchaseAmount;
    }
};