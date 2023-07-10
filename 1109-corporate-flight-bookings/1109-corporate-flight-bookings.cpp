class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {

        vector<int> output(n, 0);

        for (int i = 0; i < bookings.size(); i++)
        {
            output[bookings[i][0]-1] += bookings[i][2];
            if (bookings[i][1] < n)
            {
                output[bookings[i][1]] -= bookings[i][2];
            }
        }

        for (int i = 0; i < n-1; i++)
        {
            output[i+1] += output[i];
        }

        return output;
    }
};