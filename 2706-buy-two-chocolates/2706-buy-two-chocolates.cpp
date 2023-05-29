class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        
        sort(begin(prices), end(prices));

        if (prices[0] + prices[1] <= money)
        {
            return money - (prices[0] + prices[1]);
        }

        return money;
    }
};