class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        
        sort(begin(worker), end(worker));

        vector<pair<int,int>> profitDiff(profit.size(), {0, 0});

        for (int i = 0; i < profitDiff.size(); i++)
        {
            profitDiff[i].first = profit[i];
            profitDiff[i].second = difficulty[i];
        }

        sort(begin(profitDiff), end(profitDiff));

        int output = 0;
        int j = profitDiff.size()-1;
    
        for (int i = worker.size()-1; i >= 0; i--)
        {
            while (profitDiff[j].second > worker[i])
            {
                j--;
                if (j < 0)
                {
                    return output;
                }
            }
            output += profitDiff[j].first;
        }

        return output;
    }
};