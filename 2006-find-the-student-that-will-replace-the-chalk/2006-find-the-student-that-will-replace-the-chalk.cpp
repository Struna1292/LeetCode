class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        
        long long curr = 0;

        vector<long long> prefixSum(chalk.size(), 0);

        for (int i = 0; i < prefixSum.size(); i++)
        {
            curr += chalk[i];
            prefixSum[i] = curr;
        }

        k -= (k / prefixSum[prefixSum.size()-1]) * prefixSum[prefixSum.size()-1];

        for (int i = 0; i < prefixSum.size(); i++)
        {
            if (prefixSum[i] > k)
            {
                return i;
            }
        }
        
        return 0;
    }
};