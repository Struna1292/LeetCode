class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<int> prefixGcd;
        int currMax = nums[0];

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > currMax) {
                currMax = nums[i];
            }

            prefixGcd.push_back(gcd(nums[i], currMax));
        }

        sort(begin(prefixGcd), end(prefixGcd));

        int i = 0;
        int j = prefixGcd.size()-1;
        long long outputSum = 0;

        while (i < j) {
            outputSum += gcd(prefixGcd[i], prefixGcd[j]);

            i++;
            j--;
        }

        return outputSum;
    }
};