class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> leftCost(nums.size(), 0);
        vector<int> rightCost(nums.size(), 0);
        rightCost[1] = 1;
        leftCost[nums.size()-2] = 1;

        for (int i = 1; i < nums.size()-1; i++) {
            int left = abs(nums[i] - nums[i-1]);
            int right = abs(nums[i] - nums[i+1]);

            if (left < right || left == right) {
                leftCost[i-1] = 1;
                rightCost[i+1] = right;
            }
            else {
                leftCost[i-1] = left;
                rightCost[i+1] = 1;
            }
        }

        int currSum = 0;
        vector<int> prefix(rightCost.size(), 0);
        for (int i = 0; i < rightCost.size(); i++) {
            currSum += rightCost[i];
            prefix[i] = currSum;
        }

        currSum = 0;
        vector<int> suffix(leftCost.size(), 0);
        for (int i = leftCost.size()-1; i >= 0; i--) {
            currSum += leftCost[i];
            suffix[i] = currSum;
        }

        vector<int> output;
        for (int i = 0; i < queries.size(); i++) {
            int start = queries[i][0];
            int end = queries[i][1];

            if (start < end) {
                output.push_back(prefix[end] - prefix[start]);
            }
            else {
                output.push_back(suffix[end] - suffix[start]);
            }
        }

        return output;
    }
};