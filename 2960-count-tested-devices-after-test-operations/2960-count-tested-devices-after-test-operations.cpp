class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        
        int output = 0;

        for (int i = 0; i < batteryPercentages.size(); i++)
        {
            if (batteryPercentages[i] - output > 0)
            {
                output++;
            }
        }

        return output;
    }
};