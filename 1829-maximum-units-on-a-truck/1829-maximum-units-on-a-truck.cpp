class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        sort(begin(boxTypes), end(boxTypes), [](vector<int>& a, vector<int>& b){
            return a[1] > b[1];
        });

        int output = 0;

        for (int i = 0; i < boxTypes.size(); i++)
        {
            if (truckSize >= boxTypes[i][0])
            {
                output += boxTypes[i][0] * boxTypes[i][1];
                truckSize -= boxTypes[i][0];
            }
            else
            {
                output += boxTypes[i][1] * truckSize;
                truckSize = 0;
            }
            //cout << boxTypes[i][0] << " " << boxTypes[i][1] << endl;
        }

        return output;
    }
};