class Solution {
public:
    int maximumSum(vector<int>& nums) {
        // we need to store 3 min heaps containing numbers by remainder
        // combinations of remainders that sum is divisible by 3
        // 0,0,0 1,1,1 2,2,2 0,1,2
        vector<priority_queue<int, vector<int>, greater<int>>> minHeaps(3, priority_queue<int, vector<int>, greater<int>>());
        for (int i = 0; i < nums.size(); i++) {
            int remainder = nums[i] % 3;

            if (minHeaps[remainder].size() < 3) {
                minHeaps[remainder].push(nums[i]);
            }
            else if (minHeaps[remainder].top() < nums[i]) {
                minHeaps[remainder].pop();
                minHeaps[remainder].push(nums[i]);
            }
        }

        int output = 0;
        int sumOfEachRemainder = 0;
        int sumCounter = 0;
        for (int i = 0; i < minHeaps.size(); i++) {
            
            int remainderSum = 0;
            int remainderCounter = 0;
            while (!minHeaps[i].empty()) {
                if (minHeaps[i].size() == 1) {
                    sumOfEachRemainder += minHeaps[i].top();
                    sumCounter++;
                }

                remainderSum += minHeaps[i].top();
                minHeaps[i].pop();
                remainderCounter++;
            }

            if (remainderCounter == 3 && output < remainderSum) {
                output = remainderSum;
            }
        }

        if (sumCounter == 3 && output < sumOfEachRemainder) {
            output = sumOfEachRemainder;
        }

        return output;
    }
};