class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<pair<int,int>> bill = {{5,0},{10,0},{20,0}};
        int change = 0;
        for (int i = 0; i < bills.size(); i++)
        {
            for (int j = 0; j < bill.size(); j++)
            {
                if (bill[j].first == bills[i])
                {
                    bill[j].second++;
                }
            }
            change = bills[i] - 5;
            int j = bill.size()-1;
            while (change > 0 && j >= 0)
            {
                if (change >= bill[j].first && bill[j].second > 0)
                {
                    change -= bill[j].first;
                    bill[j].second--;
                }
                else
                {
                    j--;
                }
            }
            if (change > 0)
            {
                return false;
            }
        }
        return true;
    }
};