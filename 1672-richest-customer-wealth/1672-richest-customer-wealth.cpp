class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int currSum = 0;
        int richest = 0;
        for (int i = 0; i < accounts.size(); i++)
        {
            currSum = 0;
            for (int j = 0; j < accounts[i].size(); j++)
            {
                currSum+= accounts[i][j];
            }
            if (currSum > richest)
            {
                richest = currSum;
            }
        }
        return richest;
    }
};