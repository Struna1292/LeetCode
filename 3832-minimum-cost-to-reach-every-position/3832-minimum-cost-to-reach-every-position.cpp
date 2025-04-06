class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        
        int prevSmallest = cost[0];

        for (int i = 1; i < cost.size(); i++)
        {   
            if (cost[i] >= prevSmallest)
            {
                cost[i] = prevSmallest;
            }
            else
            {
                prevSmallest = cost[i];
            }
        }

        return cost;
    }
};