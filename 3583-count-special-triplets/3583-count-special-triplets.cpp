class Solution {
public:
    int specialTriplets(vector<int>& nums) {

        unordered_map<int, int> totalFreq;
        for (int i = 0; i < nums.size(); i++) {
            totalFreq[nums[i]]++;
        }

        unordered_map<int, int> currFreq;
        long long output = 0;
        for (int i = 0; i < nums.size(); i++) {
            currFreq[nums[i]]++;

            int curr = nums[i] * 2;

            long long leftCount = currFreq[curr];
            long long rightCount = totalFreq[curr] - leftCount;

            if (nums[i] == curr) {
                if (leftCount > 0) leftCount--;
            }

            output += leftCount * rightCount;
            output %= 1000000007;
        }

        return output;
    }
};