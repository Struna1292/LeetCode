class Solution {
public:
    int minimumCost(vector<int>& cost) {
        
        sort(begin(cost), end(cost));

        int output = 0;

        int i = cost.size()-1;

        for (; i >= 2; i-=3)
        {
            output += cost[i] + cost[i-1];
        }

        for (; i >= 0; i--)
        {
            output += cost[i];
        }

        return output;
    }
};