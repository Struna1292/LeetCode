class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        
        long long totalCosts[26] = { 0 };
        long long totalCostSum = 0;

        for (int i = 0; i < s.length(); i++) {
            totalCosts[s[i]-'a'] += cost[i];
            totalCostSum += cost[i];
        }

        long long output = 0;

        for (int i = 0; i < 26; i++) {
            if (totalCosts[i] != 0 && (output == 0 || output > totalCostSum - totalCosts[i])) {
                output = totalCostSum - totalCosts[i];
            }
        }

        return output;
    }
};