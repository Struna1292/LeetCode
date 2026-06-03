class Solution {
public:
    int bestFinishTimeHelper(vector<int>& firstStartTime, vector<int>& firstDuration, vector<int>& secondStartTime, vector<int>& secondDuration) {

        int n = firstStartTime.size();

        int bestStart = INT_MAX;
        for (int i = 0; i < n; i++) {
            bestStart = min(bestStart, firstStartTime[i] + firstDuration[i]);
        }

        int m = secondStartTime.size();
        
        int output = INT_MAX;

        for (int i = 0; i < m; i++) {
            if (secondStartTime[i] >= bestStart) {
                output = min(output, secondStartTime[i] + secondDuration[i]);
            }
            else {
                output = min(output, bestStart + secondDuration[i]);
            }
        }

        return output;
    }

    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        
        int firstTime = bestFinishTimeHelper(landStartTime, landDuration, waterStartTime, waterDuration);
        int secondTime = bestFinishTimeHelper(waterStartTime, waterDuration, landStartTime, landDuration);

        return min(firstTime, secondTime);
    }
};