class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        if (costBoth <= cost1 && costBoth <= cost2) {
            return (long long)(costBoth) * max(need1, need2);
        }

        long long output = 0;

        if (costBoth <= cost1 + cost2) {
            int minCount = min(need1, need2);
            need1 -= minCount;
            need2 -= minCount;
            output += (long long)(costBoth) * minCount;
        }

        if (costBoth < cost1) {
            output += (long long)(costBoth) * need1;
        }
        else {
            output += (long long)(cost1) * need1;
        }

        if (costBoth < cost2) {
            output += (long long)(costBoth) * need2;
        }
        else {
            output += (long long)(cost2) * need2;
        }

        return output;
    }
};