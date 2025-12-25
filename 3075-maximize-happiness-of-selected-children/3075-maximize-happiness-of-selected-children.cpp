class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(begin(happiness), end(happiness), greater<int>());

        long long output = 0;
        for (int i = 0; i < k; i++) {
            int curr = happiness[i] - i;
            if (curr <= 0) {
                break;
            }

            output += curr;
        }

        return output;
    }
};