class Solution {
public:
    int minCost(int n, int val, int k) {
        int diff = abs(n - val);
        return min(diff, k - diff);
    }

    int minOperations(vector<int>& nums, int k) {
        unordered_map<int, int> even;
        unordered_map<int, int> odd;

        for (int i = 0; i < nums.size(); i++) {
            int currMod = nums[i] % k;
            if (i % 2 == 0) {
                even[currMod]++;
            }
            else {
                odd[currMod]++;
            }
        }

        unordered_map<int, int> evenCost;
        unordered_map<int, int> oddCost;

        for (int i = 0; i < k; i++) {
            int evenCurrCost = 0;
            int oddCurrCost = 0;

            for (int j = 0; j < k; j++) {
                if (i == j) {
                    continue;
                }

                int currCost = minCost(i, j, k);

                evenCurrCost += even[j] * currCost;
                oddCurrCost += odd[j] * currCost;
            }

            evenCost[i] = evenCurrCost;
            oddCost[i] = oddCurrCost;
        }

        int output = INT_MAX;

        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                if (i == j) {
                    continue;
                }

                output = min(output, evenCost[i] + oddCost[j]);
            }
        }

        return output;
    }
};