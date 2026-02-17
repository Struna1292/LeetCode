class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        vector<bool> bulbsStatus(101, false);

        for (int i = 0; i < bulbs.size(); i++) {
            bulbsStatus[bulbs[i]] = !bulbsStatus[bulbs[i]];
        }

        vector<int> output;
        for (int i = 0; i < bulbsStatus.size(); i++) {
            if (bulbsStatus[i]) {
                output.push_back(i);
            }
        }

        return output;
    }
};