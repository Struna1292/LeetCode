class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        
        double waiting = 0;

        int currChefTime = 0;

        for (int i = 0; i < customers.size(); i++)
        {
            if (currChefTime <= customers[i][0])
            {
                currChefTime = customers[i][0];
            }
            else
            {
                waiting += currChefTime - customers[i][0];
            } 
            waiting += customers[i][1];
            currChefTime += customers[i][1];
        }

        return waiting / customers.size();
    }
};