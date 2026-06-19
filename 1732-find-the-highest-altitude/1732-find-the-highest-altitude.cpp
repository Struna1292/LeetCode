class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int largest = 0;
        int curr = 0;
        for (int i = 0; i < gain.size(); i++) {
            curr += gain[i];

            largest = max(largest, curr);
        }

        return largest;
    }
};