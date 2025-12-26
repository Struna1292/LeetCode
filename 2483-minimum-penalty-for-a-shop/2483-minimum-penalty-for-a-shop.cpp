class Solution {
public:
    int bestClosingTime(string customers) {
        vector<int> prefix(customers.length()+1, 0);
        
        int curr = 0;
        for (int i = 0; i < customers.length(); i++) {
            if (customers[i] == 'Y') {
                curr++;
            }

            prefix[i+1] = curr;
        }

        int currMissedHours = 0;

        int bestHour = -1;
        int bestPenalty = 0;
        for (int i = 0; i < prefix.size(); i++) {
            if (i > 0 && customers[i-1] == 'N') {
                currMissedHours++;
            }

            int currPenalty = (curr - prefix[i]) + currMissedHours;
            if (bestHour == -1 || currPenalty < bestPenalty) {
                bestHour = i;
                bestPenalty = currPenalty;
            }
        }

        return bestHour;
    }
};