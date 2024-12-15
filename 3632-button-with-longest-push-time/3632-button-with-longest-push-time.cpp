class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {
        
        int outputIndex = events[0][0];
        int outputTime = events[0][1];

        for (int i = 1; i < events.size(); i++)
        {
            if ((events[i][1] - events[i-1][1]) > outputTime || ((events[i][1] - events[i-1][1]) == outputTime && events[i][0] < outputIndex))
            {
                outputTime = events[i][1] - events[i-1][1];
                outputIndex = events[i][0];
            }
        }

        return outputIndex;
    }
};