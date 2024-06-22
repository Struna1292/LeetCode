class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        vector<int> nums(n, 1);

        for (int i = 0; i < k; i++)
        {

            vector<int> curr(n, 1);

            int currSum = 0;
            for (int j = 0; j < n; j++)
            {
                curr[j] = (currSum % 1000000007 + nums[j] % 1000000007) % 1000000007;
                currSum = (currSum % 1000000007 + nums[j] % 1000000007) % 1000000007;
            }

            nums = curr;
        }

        return nums[n-1] % 1000000007;
    }
};