class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(begin(costs), end(costs));

        for (int i = 0; i < costs.size(); i++) {
            if (coins < costs[i]) {
                return i;
            }

            coins -= costs[i];
        }

        return costs.size();
    }
};