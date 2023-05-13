class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(begin(costs), end(costs));
        int counter = 0;
        for (int i = 0; i < costs.size(); i++)
        {
            if (costs[i] <= coins)
            {
                counter++;
                coins -= costs[i];
            }
            else
            {
                break;
            }
        }
        return counter;
    }
};