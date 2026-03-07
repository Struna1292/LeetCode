class Solution {
public:
    int minCost(int n) {
        int cost = 0;

        while (n > 0) {
            n--;
            cost += n;
        }

        return cost;
    }
};