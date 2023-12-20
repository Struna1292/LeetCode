class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int s1 = 100;
        int s2 = 100;

        for (int i = 0; i < prices.size(); i++)
        {
            if (s1 > prices[i])
            {
                s2 = s1;
                s1 = prices[i];
            }
            else if (s2 > prices[i])
            {
                s2 = prices[i];
            }
        }

        int leftovers = money - s1 - s2;

        if (leftovers < 0)
        {
            return money;
        }
        return leftovers;
    }
};