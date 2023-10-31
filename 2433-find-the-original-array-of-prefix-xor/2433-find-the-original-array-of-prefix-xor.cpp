class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        vector<int> output(n);
        output[0] = pref[0];

        for (int i = 1; i < n; i++) {
            output[i] = pref[i] ^ pref[i - 1];
        }

        return output;
    }
};