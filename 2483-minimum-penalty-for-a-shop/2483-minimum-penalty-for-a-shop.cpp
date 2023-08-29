class Solution {
public:
    int bestClosingTime(string customers) {

        vector<int> leftN(customers.length()+1, 0);
        vector<int> rightY(customers.length()+1, 0);
        int counterN = 0;
        int counterY = 0;
        
        int j = customers.length()-1;
        int i = 0;
        for ( i = 0; i < customers.length(); i++)
        {
            leftN[i] = counterN;
            rightY[j+1] = counterY;
            if (customers[i] == 'N')
                counterN++;

            if (customers[j] == 'Y')
                counterY++;

            j--;
        }
        leftN[i] = counterN;
        rightY[j+1] = counterY;

        int index = 0;
        int smallest = leftN[0] + rightY[0];
        for (int i = 1; i < customers.length()+1; i++)
        {
            if (leftN[i] + rightY[i] < smallest)
            {
                smallest = leftN[i] + rightY[i];
                index = i;
            }
        }

        return index;
    }
};