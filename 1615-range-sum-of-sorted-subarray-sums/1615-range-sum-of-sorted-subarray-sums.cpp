class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        
        vector<int> sums;

        for (int start = 0; start < nums.size(); start++)
        {
            int curr = 0;
            for (int i = start; i < nums.size(); i++)
            {
                curr += nums[i];
                sums.push_back(curr);
            }
        }

        sort(begin(sums), end(sums));

        int output = 0;

        for (int i = left-1; i < right; i++)
        {
            output = (output + sums[i]) % 1000000007;
        }

        return output;
    }
};