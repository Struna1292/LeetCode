class Solution {
public:
    int minElement(vector<int>& nums) {
        int currMin = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            int digitsSum = 0;

            while (nums[i] > 0) {
                digitsSum += nums[i] % 10;
                nums[i] /= 10;
            }

            currMin = min(currMin, digitsSum);
        }

        return currMin;
    }
};