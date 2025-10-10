class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int output = INT_MIN;

        for (int i = 0; i < k; i++) {
            int curr = 0;
            for (int j = energy.size()-i-1; j < energy.size(); j -= k) {
                curr += energy[j];
                output = max(output, curr);
            }
        }

        return output;
    }
};