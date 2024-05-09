class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(begin(happiness), end(happiness), greater<int>());

        long long output = 0;

        for (int i = 0; i < k; i++)
        {
            if ((happiness[i] - i) > 0)
            {
                output += (happiness[i] - i);
            }
            else
            {
                break;
            }
        }

        return output;
    }
};